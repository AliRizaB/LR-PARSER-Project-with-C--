#ifndef CONSTRUCTINGTABLE_HPP
#define CONSTRUCTINGTABLE_HPP

#include <string>
#include <fstream>
#include "actionTable.hpp"
#include "gotoTable.hpp"

void ConstructActionTable(ActionTable &actionTable);
void ConstructGoToTable(GotoTableManager &gotoManager);

#endif