

#include "CommandExpression.h"

/**
 *
 * @return the command execution value.
 */
double CommandExpression::calculate() {
    return command->execute(words);
}


CommandExpression::CommandExpression(Command *command, const vector<string> &words) : command(
        command), words(words) {}

