
#include "Parser.h"


/**
 *
 * @param lines the lines of the file.
 */
Parser::Parser() : index(0) {}


/**
 * Destructor
 */
Parser::~Parser() {
    for (auto const &item:commandsTable) {
        free(item.second);
    }
}


/**
 * @param words all the words of the file.
 */
void Parser::commandParse(const vector<string> &words) {
    createFunction(words);
    for (auto const &item: words) {
        Expression *expression = commandsTable.at(words[index]); // key- worlds, value - command.
        index += (int) expression->calculate();
    }
}

void Parser:: createFunction(vector<string>lines){
    // create commands table:
    commandsTable["openDataServer"] = new CommandExpression(new OpenServerCommand(symbolTable, index),lines);
    commandsTable["connect"] = new CommandExpression(new ConnectCommand(symbolTable, index),lines);
    commandsTable["var"] = new CommandExpression(new DefineVarCommand(symbolTable,index),lines);
    commandsTable["while"] = new CommandExpression(new WhileCommand(index),lines);
    commandsTable["if"] = new CommandExpression(new IfCommand(index),lines);
    commandsTable["print"] = new CommandExpression(new PrintCommand(symbolTable,index),lines);
}
