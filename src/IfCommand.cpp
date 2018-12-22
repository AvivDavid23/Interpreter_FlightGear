

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
        index++;
    }
    else {
        while(words[index] != "}") index++;
        index++ ;
    }
}
/**
 * @param index cons'.
 */
IfCommand::IfCommand(unsigned int &index) : index(index){}

