#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include "performingOp.cpp"

enum ActionOP
{
    EMPTY,
    SHIFT,
    REDUCE,
    ACCEPT
};

class ActionObj
{
public:
    ActionOP actionOp;
    int actionId;

    ActionObj()
    {
        this->actionOp = EMPTY;
        this->actionId = 0;
    }

    ActionObj(ActionOP actionOp, int actionId)
    {
        this->actionOp = actionOp;
        this->actionId = actionId;
    }
};

struct ActionList
{
    std::string name;
    std::vector<ActionObj> operation;
};

class ActionTable
{
public:
    static std::vector<ActionList> actions;

    ActionTable(ActionList actionList)
    {
        actions.push_back(actionList);
    }

    static std::optional<ActionList> FindActionByName(std::string name)
    {
        for (size_t i = 0; i < actions.size(); i++)
        {
            if (actions[i].name == name)
            {
                return actions[i];
            }
            // If not found throw an error
            else
            {
                return std::nullopt;
            }
        }
    }
};

ActionObj FindTheOperation(ActionTable actionTable, std::string opName, int state)
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
            PerformingShiftOp();
            break;

        case REDUCE:
            PerformingReduceOp();
            break;

        case ACCEPT:
            // REPORTING THE INPUT ACCEPTED
            break;

        default:
            break;
        }
    }
}