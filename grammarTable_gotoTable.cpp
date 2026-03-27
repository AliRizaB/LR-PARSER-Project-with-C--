#include <string>
#include <vector>
#include <optional>

struct GrammarTable
{
    int grammarId;
    std::string grammarAdd;
    std::string grammarRemove;
};

std::vector<GrammarTable> grammarTable;

std::optional<GrammarTable> FindGrammar(int grammarId)
{
    for (size_t i = 0; i < grammarTable.size(); i++)
    {
        if (grammarTable.at(i).grammarId == grammarId)
        {
            return grammarTable.at(i);
        }
        else
        {
            return std::nullopt;
        }
    }
}

struct GoToTable
{
    std::string gotoLocation;
    std::vector<int> gotoValues;
};

std::vector<GoToTable> goToTable;

std::optional<int> FindGoto(std::string stackValue, std::string gotoLocation)
{

    for (size_t i = 0; i < goToTable.size(); i++)
    {
        if (goToTable.at(i).gotoLocation == gotoLocation)
        {
            return goToTable.at(i).gotoValues.at(std::stoi(stackValue));
        }
        else
        {
            return std::nullopt;
        }
    }
}