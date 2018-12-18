
#include <iostream>
#include "BindingTable.h"
#include "SymbolTable.h"
#include "PathsTable.h"

BindingTable *BindingTable::s_instance = 0;
SymbolTable *SymbolTable::s_instance = 0;
PathsTable *PathsTable::s_instance = 0;


int main() {
    std::cout << "Hello Shin!\n";
    return 0;
}