#ifndef GOTOTABLE_HPP
#define GOTOTABLE_HPP

#include <string>
#include <vector>
#include <optional>

struct GoToTable
{
    std::string gotoLocation;
    std::vector<int> gotoValues;
};

struct gotoTableManager
{
    std::vector<GoToTable> goToTable;

    std::optional<int> Find(std::string stateValue, std::string gotoLocation)
    {
        for (const auto &entry : goToTable)
        {
            if (entry.gotoLocation == gotoLocation)
                return entry.gotoValues.at(std::stoi(stateValue));
        }
        return std::nullopt;
    }
};

#endif
