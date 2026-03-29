#include "gotoTable.hpp"

// Goto Table Functions
GoToTable::GoToTable(std::string location)
{
    gotoLocation = location;
}

void GoToTable::setGotoValues(int value)
{
    gotoValues.push_back(value);
}

std::ostream &GoToTable::writeValue(std::ostream &os, int value)
{

    switch (gotoValues.at(value))
    {
    case -1:
        os << '-';
        break;

    default:
        os << gotoValues.at(value);
        break;
    }
    return os;
}

// Goto table Manager Functions
std::optional<int> GotoTableManager::Find(std::string stateValue, std::string gotoLocation)
{
    for (const auto &entry : goToTableList)
    {
        if (entry.gotoLocation == gotoLocation)
            return entry.gotoValues.at(std::stoi(stateValue));
    }
    return std::nullopt;
}

void GotoTableManager::setGotoLocationEntry(std::string location)
{
    goToTableList.push_back(GoToTable(location));
}

void GotoTableManager::setGotoValueEntry(int locationNo, int value)
{
    goToTableList.at(locationNo).setGotoValues(value);
}

int GotoTableManager::getTableSize()
{
    return goToTableList.size();
}

std::ostream &GotoTableManager::writeGotoTable(std::ostream &os)
{
    for (int i = 0; i < goToTableList.size(); i++)
    {
        os << goToTableList.at(i).gotoLocation << ' ';
    }

    os << '\n';

    for (size_t j = 0; j < goToTableList.at(0).gotoValues.size(); j++)
    {
        for (int i = 0; i < goToTableList.size(); i++)
        {
            goToTableList.at(i).writeValue(os, j);
            os << ' ';
        }
        os << '\n';
    }

    return os;
}
