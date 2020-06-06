#pragma once

#include "../operator.h"
#include "register.hpp"

class MulOperator : public Operator
{
public:
    virtual int forward()
    {
        int ret = 0;
        printf("this:%p mul forward!\n", this);
        return ret;
    }
};

OpRegister(MulOperator, "mul");