
#include <iostream>
#include "OpenServerCommand.h"
#include <thread>
#include "Shunting-Yard.h"

// TODO: thread, client-server.
int OpenServerCommand::execute(const vector<string> &words, unsigned int index) {
        int port = (int)shuntingYardAlg(words[index + 1]);
        int hz = (int)shuntingYardAlg(words[index + 2]);
    }

OpenServerCommand::OpenServerCommand(unsigned int &index) : index(index) {}
