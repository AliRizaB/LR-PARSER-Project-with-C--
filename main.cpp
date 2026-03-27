#include <iostream>
#include <fstream>
#include <stack>
#include "actionTable.hpp"

std::stack<std::string> outputStack;
std::string parsee;
ActionTable actionTable = ActionTable();

void ConstructActionTable()
{
    const std::string TABLE_FILE = "Tables/ActionTable.txt";

    std::ifstream inFile(TABLE_FILE);
    std::string value;
    int i = 0;

    if (inFile.is_open())
    {
        // Reading the first line for names.
        while (inFile >> value)
        {
            actionTable.AddActionList(ActionList(value));

            if (inFile.peek() == '\n' || inFile.peek() == '\r')
            {
                break; // Stop at new line
            }
        }

        while (inFile >> value)
        {
            ActionObj actionObj = ActionObj();
            switch (value.at(0))
            {
            case '-':
                actionObj.actionOp = EMPTY;
                break;
            case 's':
                actionObj.actionOp = SHIFT;
                break;
            case 'r':
                actionObj.actionOp = REDUCE;
                break;
            case 'a':
                actionObj.actionOp = ACCEPT;
                break;
            default:
                actionObj.actionOp = EMPTY;
                break;
            }

            if (value.size() > 1 && std::isdigit(value.at(1)))
            {
                actionObj.actionId = value.at(1) - '0';
            }
            else
                actionObj.actionId = -1;

            actionTable.actions.at(i)
                .AddOperation(actionObj);
            i++;
            if (i == actionTable.actions.size())
                i = 0;
        }
    }

    inFile.close();
}

int main(int argc, char *argv[])
{
    // std::ifstream inFile(argv[1]);
    ConstructActionTable();
    actionTable.writeTable(std::cout);

    return 0;
}