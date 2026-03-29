#include <iostream>
#include <fstream>
#include <stack>
#include "actionTable.hpp"
#include "constructingTable.hpp"

std::stack<std::string> outputStack;
std::string parsee;
ActionTable actionTable = ActionTable();
GotoTableManager gotoManager = GotoTableManager();

int main(int argc, char *argv[])
{
    // std::ifstream inFile(argv[1]);
    // ConstructActionTable(actionTable);
    ConstructGoToTable(gotoManager);
    // actionTable.writeTable(std::cout);
    gotoManager.writeGotoTable(std::cout);

    return 0;
}