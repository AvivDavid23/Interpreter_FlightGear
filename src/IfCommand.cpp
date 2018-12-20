

#include <map>
#include <sstream>
#include "IfCommand.h"

/**
 *
 * @param words
 * @param index
 * @return 1 if the condition is true, 0 otherwise.
 */
void IfCommand::execute(const vector<string> &words) {
    //Parser parser;
    ConditionParser conditionParser(index);
    if (conditionParser.execute(words)) {
    }
}

IfCommand::IfCommand(unsigned int &i) : ConditionParser(i){}

