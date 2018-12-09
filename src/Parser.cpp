
#include "Parser.h"


/**
 *
 * @param lines the lines of the file.
 */
Parser::Parser(const vector<string> &lines) : lines(lines), index(0) {
    // create commands table:
    commandsTable["openDataServer"] = new CommandExpression(new OpenServerCommand());
    commandsTable["connect"] = new CommandExpression(new ConnectCommand());
    commandsTable["var"] = new CommandExpression(new DefineVarCommand(&symbolTable));
    commandsTable["while"] = new CommandExpression(new WhileCommand());
    commandsTable["if"] = new CommandExpression(new IfCommand());
    commandsTable["print"] = new CommandExpression(new PrintCommand(symbolTable));
}

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
void Parser::lineParse() {
    for (auto const &item:lines) { // split into lines.
        string buf;                 // Have a buffer string
        stringstream ss(item);       // Insert the string into a stream
        vector<string> tokens;      // Create vector to hold our words
        while (ss >> buf) tokens.push_back(buf); // put the words into the vector
        commandParse(tokens);
    }
}

/**
 * @param lines all the words of the file.
 */
void Parser::commandParse(const vector<string> &lines) {
    for (auto const &item: lines) {
        Expression *expression = commandsTable.at(lines[index]); // key- worlds, value - command.
        index += (int)expression->calculate();
    }
}

/**
 * Creates and returns a list of commands for a While/If command
 */
list<Command *> Parser::listCreator() {
    // TODO : iterate the lines vector and return list for caller command

}

/**
 * Runs command
 * @param pExpression command expression ptr
 * @return
 */
double Parser::run(Expression *pExpression) {
    return pExpression->calculate();
}
