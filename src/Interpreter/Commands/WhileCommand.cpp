#include <utility>


#include "WhileCommand.h"


void WhileCommand::execute(const vector<string> &words) {
    unsigned int firstIndex= index;
    unsigned int startprogram;
    // while the condition is true
    while(conditionParser.execute(words)) {
        startprogram = index;
        if(firsttime) {
            // if the first time we enter the loop, create the list.
            createCommandList(words, index);
            index= startprogram;
            firsttime = false;
        }
        // run the list of commands
        for(auto const & command:commandList) command->calculate();
        index = firstIndex;
    }
}

WhileCommand::WhileCommand(unsigned int &index, std::map<string, Expression *> &map1) : index(index), conditionParser(index),
                                                                                        map(map1),firsttime(true) {}
/**
 * @param words the text
 * @param index the index
 */
void WhileCommand::createCommandList(const vector<string> &words, unsigned int &index) {
    // while we didn't reach the } in the while command
    while (words[index] != "}") {
        if(words[index] == "{") index++;
        // check if the words[index] is var, if, while or something else.
        else if (words[index] == "var") {
            commandList.push_back(map["var"]);
            if (words[index + 3] == " bind") index += 5;
            else index += 4;
        }
        else if (this->map.find(words[index]) == map.end()) {
            commandList.push_back(map["assign"]);
            index += 3;
        } else if (words[index] == "if") {
            commandList.push_back(map["if"]);
            while(words[index]!= "}") index++;
            index++;
        }
        else if (words[index] == "while") {
            commandList.push_back(map["while"]);
            while(words[index]!= "}") index++;
            index++;
        }
        else if  (this->map.find(words[index]) != map.end()) {
            commandList.push_back(map[words[index]]);
            index += 2;
        }
    }
}