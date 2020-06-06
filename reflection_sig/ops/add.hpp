#pragma once

#include "../operator.h"
#include "register.hpp"

class AddOperator : public Operator
{
public:
    virtual int forward()
    {
        int ret = 0;
        printf("this:%p add forward!\n", this);
        return ret;
    }
};

OpRegister(AddOperator, "add");