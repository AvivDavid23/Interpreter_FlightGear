

#include "CommandExpression.h"

/**
 *
 * @return the command execution value.
 */
double CommandExpression::calculate() {
    return command->execute(words, index);
}

CommandExpression::CommandExpression(Command *command, const vector<string> &words, unsigned int index) : command(
        command), words(words), index(index) {}

