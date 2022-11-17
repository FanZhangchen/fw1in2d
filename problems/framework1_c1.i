[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 100
  ny = 100
[]

[Variables]
  [rhog]
    initial_condition = 0.
  []
[]

[Kernels]
  [gnd_time_derivative]
    type = ADGNDTD
    variable = rhog
  []
  [dislocation_density_flow]
    type = DislocationDensityFlux
    variable = rhog
    backstress = 1.0
  []
[]

[Materials]
  [ssd]
    type = SSDMaterial
    rhog = rhog
  []
[]

[BCs]
[]

[Executioner]
  type = Transient
  end_time = 1.0
  dt = 0.005
  solve_type = NEWTON
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[VectorPostprocessors]
  [t_sampler]
    type = LineValueSampler
    variable = rhog
    start_point = '0 0.5 0'
    end_point = '1 0.5 0'
    num_points = 21
    sort_by = x
  []
[]

[Outputs]
  exodus = true
  [csv]
    type = CSV
    file_base = rhog_distr_c1_out
    execute_on = final
  []
[]