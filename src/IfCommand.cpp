

#include <map>
#include <sstream>
#include "IfCommand.h"

/**
 *
 * @param words
 * @param index
 * @return 1 if the condition is true, 0 otherwise.
 */
int IfCommand::execute(const vector<string> &words, unsigned int index) {
    ConditionParser conditionParser(index);
 if(conditionParser.execute(words,index)) {
     while(words[index] != "{") index++;
     return index+1;
 }
 while(words[index] != "}") index++;
    return index+1;
}

IfCommand::IfCommand(unsigned int &index,map<string, double> &commandList) : ConditionParser(index),index(index),
                                                                                commandList(commandList){}
