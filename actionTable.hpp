#ifndef ACTIONTABLE_HPP
#define ACTIONTABLE_HPP
#include <string>
#include <vector>
#include <optional>
#include <ostream>
#include "actions.hpp"

struct ActionList
{
    std::string name;
    std::vector<ActionObj> operation;

    ActionList(std::string name)
    {
        this->name = name;
    }

    void AddOperation(ActionObj action)
    {
        operation.push_back(action);
    }
};

class ActionTable
{
public:
    std::vector<ActionList> actions;

    ActionTable();
    void AddActionList(ActionList actionList);
    std::optional<ActionList> FindActionByName(std::string name);
    std::ostream &writeTable(std::ostream &os);
    void ConstructActionTable();
    void FindTheOperation(std::stack<std::string> &outputStack, std::string &inputParsee, ActionTable &actionTable, std::string opName, int state);
};

#endif