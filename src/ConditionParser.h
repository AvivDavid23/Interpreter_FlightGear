//
// Created by dvir on 12/15/18.
//

#ifndef SECONDYEARPROJECT_BIU_CONDITIONPARSER_H
#define SECONDYEARPROJECT_BIU_CONDITIONPARSER_H


#include "Command.h"


class ConditionParser : public Command {
    unsigned int index;
public:
    ConditionParser(unsigned int &i);

    int execute(const vector<string> &line, unsigned int index);
    bool checkOperator(const string &charOPerator);
};


#endif //SECONDYEARPROJECT_BIU_CONDITIONPARSER_H
