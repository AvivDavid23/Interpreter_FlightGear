

#ifndef PROJECT_CONNECTCOMMAND_H
#define PROJECT_CONNECTCOMMAND_H

#include "Command.h"
#include "map"
/**
 * Connect Command class
 */
// TODO: finish class
class ConnectCommand : public Command {
    unsigned int &index;
    map<string, double> &symbolTable;
public:
    ConnectCommand( map<string, double> &symbolTable, unsigned int &index);

    int execute(const vector<string> &words, unsigned int i);
};


#endif //PROJECT_CONNECTCOMMAND_H
