
#include <string>
#include "ConnectCommand.h"

int ConnectCommand::execute(const vector<string> &words, unsigned int i) { return 0; }

ConnectCommand::ConnectCommand(unsigned int &index) : index(index) {}
