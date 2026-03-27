#include <iostream>
#include "actionTable.cpp"
#include "parser.cpp"
#include <stack>

std::stack<std::string> outputStack;
std::string parsee;


int main()
{
    ActionList actionList = ActionList();
    ActionTable actions = ActionTable(actionList);
    return 0;
}
