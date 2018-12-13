

#ifndef PROJECT_OPENSERVERCOMMAND_H
#define PROJECT_OPENSERVERCOMMAND_H

#include <string>
#include "Command.h"
/**
 * A class which opens a thread which opens a server that listens to a specific given port
 */
// TODO: finish class
class OpenServerCommand: public Command {
public:
    OpenServerCommand();
    int execute(const vector<string> &line, unsigned int i);
};


#endif //PROJECT_OPENSERVERCOMMAND_H
