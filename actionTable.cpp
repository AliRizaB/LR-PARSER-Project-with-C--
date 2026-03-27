#include <stack>
#include <string>
#include <iostream>
#include "actionTable.hpp"
#include "performingOp.hpp"

ActionTable::ActionTable() {}

std::ostream &ActionTable::writeTable(std::ostream &os)
{
    for (int i = 0; i < actions.size(); i++)
    {
        os << actions.at(i).name << ' ';
    }

    os << '\n';

    for (size_t j = 0; j < actions.at(0).operation.size(); j++)
    {
        for (int i = 0; i < actions.size(); i++)
        {
            actions.at(i).operation.at(j).writeAction(os);
            os << ' ';
        }
        os << '\n';
    }

    return os;
}

void ActionTable::AddActionList(ActionList actionList)
{
    actions.push_back(actionList);
}

std::optional<ActionList> ActionTable::FindActionByName(std::string name)
{
    for (size_t i = 0; i < actions.size(); i++)
    {
        if (actions[i].name == name)
        {
            return actions[i];
        }
        // If not found throw an error
    }
    return std::nullopt;
}

void ActionTable::FindTheOperation(std::stack<std::string> &outputStack, std::string &inputParsee, ActionTable &actionTable, std::string opName, int state)
{
    auto action = actionTable.FindActionByName(opName);

    if (!action)
    {
        std::cerr << "Action Not Found";
    }
    else
    {
        ActionObj actionObj = (*action).operation[state];

        switch (actionObj.actionOp)
        {
        case EMPTY:
            // REPORTING INPUT FAILED;
            break;

        case SHIFT:
            PerformingShiftOp(outputStack, inputParsee, opName, actionObj.actionId);
            break;

        case REDUCE:
            PerformingReduceOp(outputStack, inputParsee, opName, actionObj.actionId);
            break;

        case ACCEPT:
            // REPORTING THE INPUT ACCEPTED
            break;

        default:
            break;
        }
    }
}