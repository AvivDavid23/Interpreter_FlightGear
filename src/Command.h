
#ifndef PROJECT_COMMAND_H
#define PROJECT_COMMAND_H
#include <vector>
#include "list"
#include <string>
#include "Shunting-Yard.h"
/**
 * Command Interface.
 */
using namespace std;

class Command {
public:
    /**
     * Execute the command.
     */
    virtual int execute(const vector<string> &line, unsigned int index) = 0;
};

#endif //PROJECT_COMMAND_H
