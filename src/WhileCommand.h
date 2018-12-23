
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
// TODO: finish class
class WhileCommand : public Command {
    list<Expression*> commandList;
    bool firsttime;
    std::map<string,Expression*> &map;
    ConditionParser conditionParser;
    unsigned int &index;
public:
    WhileCommand(unsigned int &index, std::map<string, Expression *> &map1);

    /**
     * Sets the command list for the loop
     * @param lines vector of line that we get from the lexer
     * @param currentIndex current index to start reading
     */
    void setList(vector<string>& lines);

    void execute(const vector<string> &words);

    void createCommandList(const vector<string> &words, unsigned int &i);
};


#endif //PROJECT_WHILECOMMAND_H
