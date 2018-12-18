

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
    unsigned int &index;

public:
    PrintCommand( unsigned int &index);

    int execute(const vector<string> &line);
};


#endif //PROJECT_PRINTCOMMAND_H
