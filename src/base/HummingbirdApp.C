#include "HummingbirdApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
HummingbirdApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

HummingbirdApp::HummingbirdApp(InputParameters parameters) : MooseApp(parameters)
{
  HummingbirdApp::registerAll(_factory, _action_factory, _syntax);
}

HummingbirdApp::~HummingbirdApp() {}

void 
HummingbirdApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<HummingbirdApp>(f, af, s);
  Registry::registerObjectsTo(f, {"HummingbirdApp"});
  Registry::registerActionsTo(af, {"HummingbirdApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
HummingbirdApp::registerApps()
{
  registerApp(HummingbirdApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
HummingbirdApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  HummingbirdApp::registerAll(f, af, s);
}
extern "C" void
HummingbirdApp__registerApps()
{
  HummingbirdApp::registerApps();
}
