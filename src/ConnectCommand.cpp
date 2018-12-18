
#include <string>
#include "ConnectCommand.h"

int ConnectCommand::execute(const vector<string> &line) { return 0; }

ConnectCommand::ConnectCommand(unsigned int &index) : index(index) {}
