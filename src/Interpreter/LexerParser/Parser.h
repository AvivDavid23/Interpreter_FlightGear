
#ifndef PROJECT_PARSER_H
#define PROJECT_PARSER_H

#include <sstream>
#include "../Expressions/Expression.h"
#include "../Commands/CommandExpression.h"
#include "../Commands/OpenServerCommand.h"
#include "../Commands/ConnectCommand.h"
#include "../Commands/DefineVarCommand.h"
#include "../Commands/IfCommand.h"
#include "../Commands/WhileCommand.h"
#include "../Commands/PrintCommand.h"
#include "../Tables/SymbolTable.h"
#include "../Commands/SleepCommand.h"
#include "../Commands/AssignCommand.h"

/**
 * A class which used to parse every line in the script and execute it
 */
class Parser {
private:
    unsigned int index;
    map<string, Expression *> commandsTable;
public:
     void createFunction(const vector<string> &lines);

    Parser();


    void commandParse(const vector<string> &words);


    virtual ~Parser();

};

#endif //PROJECT_PARSER_H
