#include <string>
#include <stack>
#include <iostream>
#include "PerformingOP.hpp"

void PerformingShiftOp(std::stack<std::string> &outputStack, std::string &inputParsee, std::string opName, int actionId)
{
    std::cout << "Performing Shift OPeration " << opName << ' ' << actionId << std::endl;
    outputStack.push(opName);
    outputStack.push(std::to_string(actionId));
}

void PerformingReduceOp(std::stack<std::string> &outputStack, std::string &inputParsee, GrammarManager &grammarManager, GotoTableManager &gotoManager, std::string opName, int actionId)
{
    std::cout << "Performing Reduce OPeration " << opName << ' ' << actionId << std::endl;

    auto grammar = grammarManager.Find(actionId);

    if (!grammar)
    {
        std::cerr << "Grammar Not Found";
    }
    else
    {
        int rhsLength = (*grammar).getReplaceToken();

        // 2. Pop 2 * rhsLength items (The Symbol + The State ID for each)
        for (int i = 0; i < 2 * rhsLength; ++i)
        {
            if (!outputStack.empty())
            {
                outputStack.pop();
            }
        }

        std::optional<int> gotoValue = gotoManager.Find(outputStack.top(), (*grammar).grammarUse);

        if (!gotoValue)
        {
            std::cerr << "Go To Not Found";
        }
        else
        {

            outputStack.push((*grammar).grammarUse);
            outputStack.push(std::to_string((*gotoValue)));
        }
    }
}
