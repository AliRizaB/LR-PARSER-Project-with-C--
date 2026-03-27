
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

void PerformingReduceOp()
{
}