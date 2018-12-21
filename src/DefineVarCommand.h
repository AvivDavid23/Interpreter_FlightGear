
#ifndef PROJECT_DEFINEVARCOMMAND_H
#define PROJECT_DEFINEVARCOMMAND_H

#include "Command.h"
#include "map"
#include "ExpressionsParser.h"
#include "SymbolTable.h"
#include "BindingTable.h"
/**
 * A class which defines variables from the script
 */
// TODO: finish class
class DefineVarCommand : public Command {
    unsigned int &index;
public:
    /**
     * @param index the index in the array of words
     */
    DefineVarCommand(unsigned int &index);
/**
 * @param line create a new var or update the table.
 */
    void execute(const vector<string> &line);

};


#endif //PROJECT_DEFINEVARCOMMAND_H
