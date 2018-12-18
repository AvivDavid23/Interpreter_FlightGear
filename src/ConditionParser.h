//
// Created by dvir on 12/15/18.
//

#ifndef SECONDYEARPROJECT_BIU_CONDITIONPARSER_H
#define SECONDYEARPROJECT_BIU_CONDITIONPARSER_H


#include "Command.h"


class ConditionParser : public Command {
protected:
    unsigned int index;
    list<Expression*> expression;
public:
    explicit ConditionParser(unsigned int &i);

    int execute(const vector<string> &line);
    bool checkOperator(const string &charOPerator);

    void setUpCommands(const vector<string> &words1);
};


#endif //SECONDYEARPROJECT_BIU_CONDITIONPARSER_H
