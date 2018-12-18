#include <utility>


#include "DefineVarCommand.h"


int DefineVarCommand::execute(const vector<string> &line) {
    if(line[index] != "var") {
        double number = stod(line[index+2]);
        // smblTablePtr.put("line[index]",index+2);
       for(auto &item:smblTablePtr) {
           if(item.first == line[index])
               item.second = number;
       }
    }
}

DefineVarCommand::DefineVarCommand(map<string, double> &smblTablePtr, unsigned int &i) : smblTablePtr(smblTablePtr),
                                                                                             index(i) {}
