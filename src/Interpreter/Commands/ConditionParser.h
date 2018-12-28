//
// Created by dvir on 12/15/18.
//

#ifndef SECONDYEARPROJECT_BIU_CONDITIONPARSER_H
#define SECONDYEARPROJECT_BIU_CONDITIONPARSER_H


#include "Command.h"


class ConditionParser {
    unsigned int &index;
public:
    explicit ConditionParser(unsigned int &i);

    bool execute(const vector<string> &line);

    bool checkOperator(const string &charOPerator);


};


#endif //SECONDYEARPROJECT_BIU_CONDITIONPARSER_H
