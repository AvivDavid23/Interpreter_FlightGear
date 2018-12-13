#include <utility>


#include "DefineVarCommand.h"


int DefineVarCommand::execute(const vector<string> &words, unsigned int index) {
    if(words[index] != "var") {
        double number = stod(words[index+2]);
        // smblTablePtr.put("line[index]",index+2);
       for(auto &item:smblTablePtr) {
           if(item.first == words[index])
               item.second = number;
       }
    }
}

DefineVarCommand::DefineVarCommand(map<string, double> &smblTablePtr, unsigned int &index) : smblTablePtr(smblTablePtr),
                                                                                             index(index) {}
