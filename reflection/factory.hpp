#pragma once
#include <string>
#include "operator.h"

class Factory
{
public:
    virtual Operator* create() = 0;
};

#define BuildOpFactory(op) class op##Factory : public Factory {public: virtual Operator* create() {return new op();} };