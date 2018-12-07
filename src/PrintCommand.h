

#ifndef PROJECT_PRINTCOMMAND_H
#define PROJECT_PRINTCOMMAND_H

#include <iostream>
#include "Command.h"
#include "map"

/**
 * Command which prints something to the stdout
 */
class PrintCommand : public Command {
    string output;
    map<string, double> &smblTablePtr;
public:
    PrintCommand(map<string, double> &smblTablePtr);

    void setOutput(string& str);

    int execute();
};


#endif //PROJECT_PRINTCOMMAND_H
