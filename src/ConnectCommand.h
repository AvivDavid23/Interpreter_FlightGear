

#ifndef PROJECT_CONNECTCOMMAND_H
#define PROJECT_CONNECTCOMMAND_H

#include "Command.h"
/**
 * Connect Command class
 */
// TODO: finish class
class ConnectCommand : public Command {
    unsigned int &index;
public:
    ConnectCommand(unsigned int &index);

    int execute(const vector<string> &words, unsigned int i);
};


#endif //PROJECT_CONNECTCOMMAND_H
