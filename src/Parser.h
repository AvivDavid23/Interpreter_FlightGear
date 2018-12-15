
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
public:
    void createFunction(vector<string> lines);

    Parser();


    void commandParse(const vector<string> &words);


    virtual ~Parser();

};

#endif //PROJECT_PARSER_H
