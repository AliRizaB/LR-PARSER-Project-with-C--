#include <iostream>
#include <fstream>
#include <stack>
#include "actionTable.hpp"
#include "constructingTable.hpp"

std::stack<std::string> outputStack;
std::string parsee;
ActionTable actionTable = ActionTable();
GotoTableManager gotoManager = GotoTableManager();
GrammarManager grammarManager = GrammarManager();

int main(int argc, char *argv[])
{
    // std::ifstream inFile(argv[1]);

    // ConstructActionTable(actionTable);
    // actionTable.writeTable(std::cout);

    // ConstructGoToTable(gotoManager);
    // gotoManager.writeGotoTable(std::cout);

    ConstructGrammarTable(grammarManager);
    grammarManager.writeGrammarTable(std::cout);
    return 0;
}