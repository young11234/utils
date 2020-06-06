#pragma once

#include "../operator.h"
#include "../factory.hpp"
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

BuildOpFactory(AddOperator)

OpFactoryRegister(AddOperatorFactory, "add");