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
    /**
     * @param index in the text
     */
    SleepCommand(unsigned int &index);
/**
 * @param line the words in the text
 */
    void execute(const vector<string> &line);
};


#endif //SECONDYEARPROJECT_BIU_SLEEPCOMMAND_H
