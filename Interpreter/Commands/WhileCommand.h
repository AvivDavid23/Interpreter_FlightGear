
#ifndef PROJECT_WHILECOMMAND_H
#define PROJECT_WHILECOMMAND_H

#include "Command.h"
#include "ConditionParser.h"
#include "CommandExpression.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include <iostream>
#include <map>
/**
 * A command which runs while a condition is satisfied
 */
class WhileCommand : public Command {
    list<Expression*> commandList;
    bool firsttime;
    std::map<string,Expression*> &map;
    ConditionParser conditionParser;
    unsigned int &index;
public:
    WhileCommand(unsigned int &index, std::map<string, Expression *> &map1);
/**
 * @param words execute the while loop.
 */
    void execute(const vector<string> &words);
/**
 * @param words the words.
 * @param i the index
 * create the commands list.
 */
    void createCommandList(const vector<string> &words, unsigned int &i);
};


#endif //PROJECT_WHILECOMMAND_H
