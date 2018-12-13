
#ifndef PROJECT_PARSER_H
#define PROJECT_PARSER_H

#include <sstream>
#include "Expression.h"
#include "CommandExpression.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "IfCommand.h"
#include "WhileCommand.h"
#include "PrintCommand.h"

/**
 * A class which used to parse every line in the script and execute it
 */
class Parser {

private:
    unsigned int index;
    map<string, Expression *> commandsTable;
    map<string, double> symbolTable;
    vector<string> words;
public:
    void createFunction(vector<string>lines);
    Parser();

    void lineParse();

    void commandParse(const vector<string> &line);

    list<Command*> listCreator();

    virtual ~Parser();

    double run(Expression *pExpression);
};

#endif //PROJECT_PARSER_H
