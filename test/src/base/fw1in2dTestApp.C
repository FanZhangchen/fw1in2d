//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "fw1in2dTestApp.h"
#include "fw1in2dApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
fw1in2dTestApp::validParams()
{
  InputParameters params = fw1in2dApp::validParams();
  return params;
}

fw1in2dTestApp::fw1in2dTestApp(InputParameters parameters) : MooseApp(parameters)
{
  fw1in2dTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

fw1in2dTestApp::~fw1in2dTestApp() {}

void
fw1in2dTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  fw1in2dApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"fw1in2dTestApp"});
    Registry::registerActionsTo(af, {"fw1in2dTestApp"});
  }
}

void
fw1in2dTestApp::registerApps()
{
  registerApp(fw1in2dApp);
  registerApp(fw1in2dTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
fw1in2dTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  fw1in2dTestApp::registerAll(f, af, s);
}
extern "C" void
fw1in2dTestApp__registerApps()
{
  fw1in2dTestApp::registerApps();
}
