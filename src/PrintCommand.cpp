

#include "PrintCommand.h"

PrintCommand::PrintCommand(map<string, double> &smblTablePtr) : smblTablePtr(smblTablePtr) {}

void PrintCommand::setOutput(string &str) { output = str; }

int PrintCommand::execute() {

    // Checks if output is in symbol map. if so, prints his value. else, prints output
    smblTablePtr.find(output) == smblTablePtr.end() ? cout << output : cout << smblTablePtr.at(output);
    cout << "\n";
    return 1;
}