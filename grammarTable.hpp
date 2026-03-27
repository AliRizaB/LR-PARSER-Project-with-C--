#ifndef GRAMMARTABLE_HPP
#define GRAMMARTABLE_HPP

#include <string>
#include <vector>
#include <optional>

struct GrammarTable
{
    int grammarId;
    std::string grammarAdd;
    std::string grammarRemove;
};

struct GrammarManager
{
    std::vector<GrammarTable> table;

    std::optional<GrammarTable> Find(int id)
    {
        for (const auto &entry : table)
        {
            if (entry.grammarId == id)
                return entry;
        }
        return std::nullopt;
    }
};

#endif