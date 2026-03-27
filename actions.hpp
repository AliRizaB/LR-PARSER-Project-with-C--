#ifndef ACTIONS_HPP
#define ACTIONS_HPP
#include <ostream>

enum ActionOP
{
    EMPTY,
    SHIFT,
    REDUCE,
    ACCEPT
};

class ActionObj
{
public:
    ActionOP actionOp;
    int actionId;

    ActionObj();
    ActionObj(ActionOP actionOp, int actionId);
    std::ostream &writeAction(std::ostream &os);
};

#endif