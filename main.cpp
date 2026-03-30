#include <iostream>
#include <fstream>
#include <stack>
#include <sstream>
#include "actionTable.hpp"
#include "constructingTable.hpp"
#include "performingOp.hpp"

void printStack(std::stack<std::string> s)
{ // Note: Passed by value (creates a copy)
    std::cout << std::endl;
    while (!s.empty())
    {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}

int StartParsing(std::stack<std::string> &outputStack, std::string &inputParsee, ActionTable &actionTable, GrammarManager &grammarManager, GotoTableManager &gotoManager)
{
    std::string readParseePart;
    std::string opName;
    int complete = 0;
    int state;

    std::stringstream ss(inputParsee);
    ss >> opName;

    while (complete == 0)
    {
        std::cout << std::string(50, '=');
        printStack(outputStack);
        std::cout << std::string(50, '=');
        auto action = actionTable.FindActionByName(opName);
        std::cout << '\n'
                  << opName << "----\n";

        if (!action)
        {
            std::cerr << "Action Not Found";
            complete = -1;
        }
        else
        {
            state = std::stoi(outputStack.top());
            std::cout << state << std::endl;
            ActionObj actionObj = (*action).operation[state];
            actionObj.writeAction(std::cout) << std::endl;

            switch (actionObj.actionOp)
            {
            case EMPTY:
                complete = -1;
                break;

            case SHIFT:
                PerformingShiftOp(outputStack, inputParsee, opName, actionObj.actionId);
                complete = 0;
                ss >> opName;
                break;

            case REDUCE:
                PerformingReduceOp(outputStack, inputParsee, grammarManager, gotoManager, opName, actionObj.actionId);
                complete = 0;
                break;

            case ACCEPT:
                complete = 1;
                break;

            default:
                complete = -1;
                break;
            }
        }
    }

    return complete;
}

std::stack<std::string> outputStack;
std::string inputParsee;
ActionTable actionTable = ActionTable();
GotoTableManager gotoManager = GotoTableManager();
GrammarManager grammarManager = GrammarManager();

int main(int argc, char *argv[])
{
    // Constructing Tables
    ConstructActionTable(actionTable);
    ConstructGoToTable(gotoManager);
    ConstructGrammarTable(grammarManager);

    outputStack.push("0");
    // Complete
    // 0  == Not complete
    // 1  == Complete
    // -1 == Error
    int complete = 0;

    // Getting the input file
    // std::ifstream inFile(argv[1]);
    std::ifstream inFile("input1.txt");

    if (inFile.is_open())
    {
        std::getline(inFile, inputParsee);

        complete = StartParsing(outputStack, inputParsee, actionTable, grammarManager, gotoManager);
        if (complete == 1)
        {
            std::cout << "Accepted The Input";
        }
        else
        {
            std::cout << "Not Accepted The Input";
        }
    }
    else
    {
        std::cerr << "Error Opening the input file";
    }

    return 0;
}
