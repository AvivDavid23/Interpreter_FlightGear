

#ifndef PROJECT_CONNECTCOMMAND_H
#define PROJECT_CONNECTCOMMAND_H

#include "Command.h"
/**
 * Connect Command class
 */
// TODO: finish class
class ConnectCommand : public Command {
public:
    ConnectCommand();

    int execute(const vector<string> &line, unsigned int i);
};


#endif //PROJECT_CONNECTCOMMAND_H
