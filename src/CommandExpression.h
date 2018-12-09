
#ifndef PROJECT_COMMANDEXPRESSION_H
#define PROJECT_COMMANDEXPRESSION_H

#include "Expression.h"
#include "Command.h"

class CommandExpression : public Expression {
public:
    Command *command;

     CommandExpression(Command *command);

    virtual double calculate();
    void setWords(const vector<string> &words);

protected:
    vector<string> words;
};


#endif //PROJECT_COMMANDEXPRESSION_H