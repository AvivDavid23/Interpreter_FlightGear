//
// Created by aviv on 12/20/18.
//

#ifndef SECONDYEARPROJECT_BIU_SLEEPCOMMAND_H
#define SECONDYEARPROJECT_BIU_SLEEPCOMMAND_H


#include "Command.h"
#include "thread"
#include "ExpressionsParser.h"
class SleepCommand : public Command{
    unsigned int &index;
public:
    SleepCommand(unsigned int &index);

    void execute(const vector<string> &line);
};


#endif //SECONDYEARPROJECT_BIU_SLEEPCOMMAND_H
