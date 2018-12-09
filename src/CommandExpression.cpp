

#include "CommandExpression.h"

/**
 *
 * @return the command execution value.
 */
double CommandExpression::calculate() {
    return command->execute();
}

CommandExpression::CommandExpression(Command *command) : command(command) {}

void CommandExpression::setWords(const vector<string> &words) {
    CommandExpression::words = words;
}

