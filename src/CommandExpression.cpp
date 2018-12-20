

#include "CommandExpression.h"

/**
 *
 * @return the command execution value.
 */
double CommandExpression::calculate() {
    command->execute(words);
    return 0;
}


CommandExpression::CommandExpression(Command *command, const vector<string> &words) : command(
        command), words(words) {}

