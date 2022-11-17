//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "ADGNDTD.h"

registerMooseObject("fw1in2dApp", ADGNDTD);

InputParameters
ADGNDTD::validParams()
{
  InputParameters params = ADTimeDerivative::validParams();
  params.addClassDescription("The time derivative operator with the weak form of $(\\psi_i, "
                             "\\frac{\\partial rhog}{\\partial t})$.");
  return params;
}

ADGNDTD::ADGNDTD(const InputParameters & parameters)
  : ADTimeDerivative(parameters)
{
}

ADReal
ADGNDTD::precomputeQpResidual()
{
  return ADTimeDerivative::precomputeQpResidual();
}