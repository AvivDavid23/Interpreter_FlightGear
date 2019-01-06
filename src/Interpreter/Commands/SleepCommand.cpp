//
// Created by aviv on 12/20/18.
//

#include "SleepCommand.h"

SleepCommand::SleepCommand(unsigned int &index) : index(index) {}

void SleepCommand::execute(const vector<string> &line) {
    ++index;
    // sleep the thread.
    this_thread::sleep_for(std::chrono::milliseconds(
            (int)ExpressionsParser::shuntingYardAlg(ExpressionsParser::varsExtrication(line[index]))));
    ++index;
}