//
// Created by aviv on 12/20/18.
//

#ifndef SECONDYEARPROJECT_BIU_ASSIGNCOMMAND_H
#define SECONDYEARPROJECT_BIU_ASSIGNCOMMAND_H

#include "Command.h"
#include "ExpressionsParser.h"

class AssignCommand : public Command{
    unsigned int &index;
public:
    AssignCommand(unsigned int &index);

    void execute(const vector<string> &line);
};


#endif //SECONDYEARPROJECT_BIU_ASSIGNCOMMAND_H
