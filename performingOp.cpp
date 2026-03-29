#include <string>
#include <stack>
#include <iostream>
#include "PerformingOP.hpp"

void PerformingShiftOp(std::stack<std::string> &outputStack, std::string &inputParsee, std::string opName, int actionId)
{
    outputStack.push(opName);
    outputStack.push(std::to_string(actionId));

    // Removing the the input
    size_t pos = inputParsee.find(' ');
    if (pos != std::string::npos)
    {
        inputParsee.erase(0, pos + 1);
    }
    else
    {
        inputParsee.clear();
    }
}

void PerformingReduceOp(std::stack<std::string> &outputStack, std::string &inputParsee, std::string opName, int actionId)
{
    GotoTableManager gotoManager = GotoTableManager();
    GrammarManager grammarManager = GrammarManager();

    auto grammar = grammarManager.Find(actionId);

    if (!grammar)
    {
        std::cerr << "Grammar Not Found";
    }
    else
    {
        while (outputStack.top() == (*grammar).grammarReplace)
        {
            outputStack.pop();
        }
        // The grammarRemove is also get removed
        outputStack.pop();

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