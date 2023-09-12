//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "HummingbirdTestApp.h"
#include "HummingbirdApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
HummingbirdTestApp::validParams()
{
  InputParameters params = HummingbirdApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

HummingbirdTestApp::HummingbirdTestApp(InputParameters parameters) : MooseApp(parameters)
{
  HummingbirdTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

HummingbirdTestApp::~HummingbirdTestApp() {}

void
HummingbirdTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  HummingbirdApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"HummingbirdTestApp"});
    Registry::registerActionsTo(af, {"HummingbirdTestApp"});
  }
}

void
HummingbirdTestApp::registerApps()
{
  registerApp(HummingbirdApp);
  registerApp(HummingbirdTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
HummingbirdTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  HummingbirdTestApp::registerAll(f, af, s);
}
extern "C" void
HummingbirdTestApp__registerApps()
{
  HummingbirdTestApp::registerApps();
}
