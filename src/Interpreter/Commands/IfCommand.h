
#ifndef PROJECT_IFCOMMAND_H
#define PROJECT_IFCOMMAND_H

#include <iostream>
#include "ConditionParser.h"
#include "../LexerParser/Parser.h"
/**
 * A command which runs if a condition is satisfied
 */
class IfCommand : public Command{
    unsigned int &index;
    ConditionParser conditionParser;
public:
    void execute(const vector<string> &words);

    IfCommand(unsigned int &index);

    virtual ~IfCommand();
};


#endif //PROJECT_IFCOMMAND_H
