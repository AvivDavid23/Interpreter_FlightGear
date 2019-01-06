

#ifndef PROJECT_PRINTCOMMAND_H
#define PROJECT_PRINTCOMMAND_H

#include <iostream>
#include "Command.h"
#include "../Tables/SymbolTable.h"

/**
 * Command which prints something to the stdout
 */
class PrintCommand : public Command {
    string output;
    unsigned int &index;

public:
    PrintCommand( unsigned int &index);
/**
 * @param line print the line[index] .
 */
    void execute(const vector<string> &line);
};


#endif //PROJECT_PRINTCOMMAND_H
