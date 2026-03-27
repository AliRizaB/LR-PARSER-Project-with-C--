#ifndef PERFORMINGOP_HPP
#define PERFORMINGOP_HPP

#include <string>
#include <stack>
#include <iostream>
#include "gotoTable.hpp"
#include "grammarTable.hpp"

void PerformingShiftOp(std::stack<std::string> &outputStack, std::string &inputParsee, std::string opName, int actionId);
void PerformingReduceOp(std::stack<std::string> &outputStack, std::string &inputParsee, std::string opName, int actionId);


#endif