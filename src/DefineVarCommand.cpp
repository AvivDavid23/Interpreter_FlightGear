
#include "DefineVarCommand.h"

DefineVarCommand::DefineVarCommand(map<string, double> *smblTablePtr) : smblTablePtr(smblTablePtr){}

int DefineVarCommand::execute() { return 0; }