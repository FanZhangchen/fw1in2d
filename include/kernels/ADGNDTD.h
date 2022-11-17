#pragma once

#include "ADTimeDerivative.h"

class ADGNDTD : public ADTimeDerivative
{
public:
  static InputParameters validParams();

  ADGNDTD(const InputParameters & parameters);

protected:
  virtual ADReal precomputeQpResidual() override;
};
