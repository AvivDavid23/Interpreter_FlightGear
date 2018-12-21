

#include "CommandExpression.h"

/**
 *
 * @return the command execution value.
 */
double CommandExpression::calculate() {
         command->execute(words);
    return 0;
    command->execute(words);
    return 0;
}

/**
 * @param command the command
 * @param words the array of orders.
 */
CommandExpression::CommandExpression(Command *command, const vector<string> &words) : command(
        command), words(words) {}

