#include "grammarTable.hpp"



// Grammar rule Functions
GrammarRule::GrammarRule(int Id, std::string use, std::string replace)
{
    grammarId = Id;
    grammarUse = use;
    grammarReplace = replace;
}

std::ostream &GrammarRule::writeRule(std::ostream &os)
{
    os << grammarId << ' ' << grammarUse << " -> " << grammarReplace;

    return os;
}

// Grammar Manager Functions
std::optional<GrammarRule> GrammarManager::Find(int id)
{
    for (const auto &entry : grammarTable)
    {
        if (entry.grammarId == id)
            return entry;
    }
    return std::nullopt;
}

void GrammarManager::setGrammar(int Id, std::string use, std::string replace)
{
    grammarTable.push_back(GrammarRule(Id, use, replace));
}

std::ostream &GrammarManager::writeGrammarTable(std::ostream &os)
{
    for (auto &entry : grammarTable)
    {
        entry.writeRule(os);
        os << '\n';
    }

    return os;
}