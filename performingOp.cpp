#include "grammarTable_gotoTable.cpp"

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
    auto grammar = FindGrammar(actionId);

    if (!grammar)
    {
        std::cerr << "Grammar Not Found";
    }
    else
    {
        while (outputStack.top() == (*grammar).grammarRemove)
        {
            outputStack.pop();
        }
        // The grammarRemove is also get removed
        outputStack.pop();

        std::optional<int> gotoValue = FindGoto(outputStack.top(), (*grammar).grammarAdd);

        if (!gotoValue)
        {
            std::cerr << "Go To Not Found";
        }
        else
        {

            outputStack.push((*grammar).grammarAdd);
            outputStack.push(std::to_string((*gotoValue)));
        }
    }
}