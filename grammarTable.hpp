#ifndef GRAMMARTABLE_HPP
#define GRAMMARTABLE_HPP

#include <string>
#include <vector>
#include <optional>
#include <iostream>

struct GrammarRule
{
    int grammarId;
    std::string grammarUse;
    std::string grammarReplace;

    GrammarRule(int Id, std::string use, std::string replace);

    std::ostream &writeRule(std::ostream &os);
};

struct GrammarManager
{
    std::vector<GrammarRule> grammarTable;

    std::optional<GrammarRule> Find(int id);

    void setGrammar(int Id, std::string use, std::string replace);

    std::ostream &writeGrammarTable(std::ostream &os);
};

#endif