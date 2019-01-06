
#ifndef PROJECT_COMMAND_H
#define PROJECT_COMMAND_H
#include <vector>
#include "list"
#include <string>
#include <mutex>
#include "../Expressions/ExpressionsParser.h"
static std::mutex globalMutex;

/**
 * Command Interface.
 */
using namespace std;

class Command {
public:
    /**
     * Execute the command.
     */
    virtual void execute(const vector<string> &line) = 0;
};

#endif //PROJECT_COMMAND_H
