#ifndef CONSTRUCTINGTABLE_HPP
#define CONSTRUCTINGTABLE_HPP

#include <string>
#include <fstream>
#include <sstream>
#include "actionTable.hpp"
#include "gotoTable.hpp"
#include "grammarTable.hpp"

void ConstructActionTable(ActionTable &actionTable);
void ConstructGoToTable(GotoTableManager &gotoManager);
void ConstructGrammarTable(GrammarManager &grammarManager);

#endif