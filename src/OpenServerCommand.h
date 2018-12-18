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
    map<string, double> &symbolTable;

public:
    OpenServerCommand(map<string, double> &symbolTable, unsigned int &index);


    int execute(const vector<string> &words);
};


#endif //PROJECT_OPENSERVERCOMMAND_H