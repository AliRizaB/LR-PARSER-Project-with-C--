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

    GoToTable(std::string location);

    void setGotoValues(int value);

    std::ostream &writeValue(std::ostream &os, int value);
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
