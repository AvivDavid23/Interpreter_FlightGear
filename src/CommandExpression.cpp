

#include "CommandExpression.h"

/**
 *
 * @return the command execution value.
 */
double CommandExpression::calculate() {
    return command->execute(words, index);
}

void CommandExpression::setIndex(unsigned int index) {
    CommandExpression::index = index;
}

CommandExpression::CommandExpression(Command *command, const vector<string> &words) : command(
        command), words(words) {}

