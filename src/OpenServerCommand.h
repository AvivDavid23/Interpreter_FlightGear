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
    /**
     * @param index the index of the array
     */
    OpenServerCommand(unsigned int &index);
    /**
     * @param words the array of words
     * get the port and the hz, and create a thread that run the DataReaderServer.
     */
    void execute(const vector<string> &words);
};


#endif //PROJECT_OPENSERVERCOMMAND_H