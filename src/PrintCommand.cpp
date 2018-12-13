

#include "PrintCommand.h"

void PrintCommand::setOutput(string &str) { output = str; }

int PrintCommand::execute(const vector<string> &words, unsigned int i) {

    // Checks if output is in symbol map. if so, prints his value. else, prints output
    smblTablePtr.find(output) == smblTablePtr.end() ? cout << output : cout << smblTablePtr.at(output);
    cout << "\n";
    return 1;
}

PrintCommand::PrintCommand(map<string, double> &smblTablePtr, unsigned int &index) : smblTablePtr(smblTablePtr),
                                                                                     index(index) {}
