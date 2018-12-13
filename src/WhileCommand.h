
#ifndef PROJECT_WHILECOMMAND_H
#define PROJECT_WHILECOMMAND_H

#include "Command.h"
#include <iostream>
/**
 * A command which runs while a condition is satisfied
 */
// TODO: finish class
class WhileCommand : public Command {
    list<Command*> commandList;
public:
    WhileCommand();
    /**
     * Sets the command list for the loop
     * @param lines vector of line that we get from the lexer
     * @param currentIndex current index to start reading
     */
    void setList(vector<string>& lines, unsigned int currentIndex);

    int execute(const vector<string> &line, unsigned int i);
};


#endif //PROJECT_WHILECOMMAND_H
