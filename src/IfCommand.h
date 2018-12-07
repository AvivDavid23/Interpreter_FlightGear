
#ifndef PROJECT_IFCOMMAND_H
#define PROJECT_IFCOMMAND_H

#include <iostream>
#include "Command.h"
/**
 * A command which runs if a condition is satisfied
 */
// TODO: finish class
class IfCommand : public Command {
    list<Command*> commandList;
public:
    IfCommand();

    /**
     * Sets the command list for the condition
     * @param lines vector of line that we get from the lexer
     * @param currentIndex current index to start reading
     */
    void setList(vector<string> &lines, unsigned int currentIndex);

    int execute();
};


#endif //PROJECT_IFCOMMAND_H
