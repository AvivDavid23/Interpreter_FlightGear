
#include "DefineVarCommand.h"


int DefineVarCommand::execute(const vector<string> &line) {
    if(line[index] != "var") {
        double number = stod(line[index+2]);
        if(SymbolTable::instance()->atTable(line[index]))
            SymbolTable::instance()->setValue(line[index], number);

    }
}

DefineVarCommand::DefineVarCommand(unsigned int &i) :index(i) {}
