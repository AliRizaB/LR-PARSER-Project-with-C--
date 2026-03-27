#include "actions.hpp"
#include <iostream>

ActionObj::ActionObj()
{
    this->actionOp = EMPTY;
    this->actionId = 0;
}

ActionObj::ActionObj(ActionOP actionOp, int actionId)
{
    this->actionOp = actionOp;
    this->actionId = actionId;
}

std::ostream &ActionObj::writeAction(std::ostream &os)
{
    char opValue;

    switch (actionOp)
    {
    case SHIFT:
        opValue = 's';
        break;
    case REDUCE:
        opValue = 'r';
        break;
    case EMPTY:
        opValue = '-';
        break;
    case ACCEPT:
        opValue = 'a';
        break;
    default:
        opValue = ' ';
        break;
    }

    os << opValue;
    if (actionId != -1)
        os << actionId;
    return os;
}