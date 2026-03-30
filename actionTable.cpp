
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