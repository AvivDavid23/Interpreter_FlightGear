
#ifndef PROJECT_DEFINEVARCOMMAND_H
#define PROJECT_DEFINEVARCOMMAND_H

#include "Command.h"
#include "map"
/**
 * A class which defines variables from the script
 */
 // TODO: finish class
class DefineVarCommand : public Command{
    map<string, double> &smblTablePtr;
    unsigned int &index;
public:
    DefineVarCommand(map<string, double> &smblTablePtr, unsigned int &index);

public:

    int execute(const vector<string> &words, unsigned int i);

};


#endif //PROJECT_DEFINEVARCOMMAND_H
