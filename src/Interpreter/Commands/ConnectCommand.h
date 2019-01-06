

#ifndef PROJECT_CONNECTCOMMAND_H
#define PROJECT_CONNECTCOMMAND_H

#include "Command.h"
#include "../ServerClient/DataWriterClient.h"
/**
 * Connect Command class
 */
class ConnectCommand : public Command {
    unsigned int &index;
public:
    ConnectCommand(unsigned int &index);

    void execute(const vector<string> &words);
};


#endif //PROJECT_CONNECTCOMMAND_H
