
#ifndef PROJECT_COMMAND_H
#define PROJECT_COMMAND_H
#include <vector>
#include "list"
/**
 * Command Interface.
 */
using namespace std;

class Command {
public:
    /**
     * Execute the command.
     */
    virtual int execute() = 0;
};

#endif //PROJECT_COMMAND_H
