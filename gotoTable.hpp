#ifndef GOTOTABLE_HPP
#define GOTOTABLE_HPP

#include <string>
#include <vector>
#include <optional>
#include <iostream>

struct GoToTable
{
    std::string gotoLocation;
    std::vector<int> gotoValues;

    GoToTable(std::string location)
    {
        gotoLocation = location;
    }

    void setGotoValues(int value)
    {
        gotoValues.push_back(value);
    }

    std::ostream &writeValue(std::ostream &os, int value)
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
};

struct GotoTableManager
{
    std::vector<GoToTable> goToTableList;

    std::optional<int> Find(std::string stateValue, std::string gotoLocation);
    void setGotoLocationEntry(std::string location);
    void setGotoValueEntry(int locationNo, int value);
    int getTableSize();
    std::ostream &writeGotoTable(std::ostream &os);
};
#endif
