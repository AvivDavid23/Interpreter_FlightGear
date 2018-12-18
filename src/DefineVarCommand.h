
#ifndef PROJECT_DEFINEVARCOMMAND_H
#define PROJECT_DEFINEVARCOMMAND_H

#include "Command.h"
#include "map"
#include "SymbolTable.h"

/**
 * A class which defines variables from the script
 */
// TODO: finish class
class DefineVarCommand : public Command {
    unsigned int &index;
public:
    DefineVarCommand(unsigned int &index);

    int execute(const vector<string> &line);

};


#endif //PROJECT_DEFINEVARCOMMAND_H
