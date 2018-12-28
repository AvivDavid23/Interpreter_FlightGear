
#ifndef PROJECT_COMMANDEXPRESSION_H
#define PROJECT_COMMANDEXPRESSION_H

#include "../Expressions/Expression.h"
#include "Command.h"

class CommandExpression : public Expression {
protected:
    Command *command;
    vector<string> words;
    unsigned int index;
public:
    CommandExpression(Command *command, const vector<string> &words);

    virtual double calculate();

    virtual ~CommandExpression();


};



#endif //PROJECT_COMMANDEXPRESSION_H