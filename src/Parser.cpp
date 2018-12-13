
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
 * The function uses the vector of lines, each line will be parsed
 */
 /*
void Parser::lineParse() {
    for (auto const &item:lines) { // split into lines.
        string buf;                 // Have a buffer string
        stringstream ss(item);       // Insert the string into a stream
        vector<string> tokens;      // Create vector to hold our words
        while (ss >> buf) tokens.push_back(buf); // put the words into the vector
        commandParse(tokens);
    }
}
*/
/**
 * @param lines all the words of the file.
 */
void Parser::commandParse(const vector<string> &lines) {
    createFunction(lines);
    for (auto const &item: lines) {
        Expression *expression = commandsTable.at(lines[index]); // key- worlds, value - command.
        index += (int) expression->calculate();
    }
}

void Parser:: createFunction(vector<string>lines){
    // create commands table:
    commandsTable["openDataServer"] = new CommandExpression(new OpenServerCommand(),lines,index);
    commandsTable["connect"] = new CommandExpression(new ConnectCommand(),lines,index);
    commandsTable["var"] = new CommandExpression(new DefineVarCommand(&symbolTable),lines,index);
    commandsTable["while"] = new CommandExpression(new WhileCommand(),lines,index);
    commandsTable["if"] = new CommandExpression(new IfCommand(),lines,index);
    commandsTable["print"] = new CommandExpression(new PrintCommand(symbolTable),lines,index);
}
