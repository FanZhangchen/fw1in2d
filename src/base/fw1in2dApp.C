#include "fw1in2dApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
fw1in2dApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

fw1in2dApp::fw1in2dApp(InputParameters parameters) : MooseApp(parameters)
{
  fw1in2dApp::registerAll(_factory, _action_factory, _syntax);
}

fw1in2dApp::~fw1in2dApp() {}

void
fw1in2dApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"fw1in2dApp"});
  Registry::registerActionsTo(af, {"fw1in2dApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
fw1in2dApp::registerApps()
{
  registerApp(fw1in2dApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
fw1in2dApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  fw1in2dApp::registerAll(f, af, s);
}
extern "C" void
fw1in2dApp__registerApps()
{
  fw1in2dApp::registerApps();
}
