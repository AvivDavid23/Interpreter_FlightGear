

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
    if (!conditionParser.execute(words)) {
        while(words[index] != "}") index++;
        index++ ;
    }
}
/**
 * @param index cons'.
 */
IfCommand::IfCommand(unsigned int &index) : index(index),conditionParser(this->index){}

