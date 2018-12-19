#ifndef PROJECT_OPENSERVERCOMMAND_H
#define PROJECT_OPENSERVERCOMMAND_H

#include <string>
#include "Command.h"
#include "map"
#include "DataReaderServer.h"
/**
 * A class which opens a thread which opens a server that listens to a specific given port
 */
// TODO: finish class
class OpenServerCommand : public Command {
    unsigned int &index;

public:
    OpenServerCommand(unsigned int &index);
    vector<string> argv (const  vector<string> & words);
    int execute(const vector<string> &words);
    bool is_number(const std::string& s);
};


#endif //PROJECT_OPENSERVERCOMMAND_H