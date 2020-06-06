#pragma once
#include <string>
#include <map>
#include "operator.h"

template <typename sit>
class singleton
{
public:
    static sit* instance()
    {
        static sit sit_obj;
        return &sit_obj;
    }
};

class Suite : public singleton<Suite>
{
public:
    void add(const std::string& name, Operator* p)
    {
        reg_map_[name] = p;
    }

    Operator* find(const std::string& name)
    {
        Operator* p = NULL;
        if (reg_map_.find(name) != reg_map_.end())
        {
            p = reg_map_[name];
        }
        return p;
    }
private:
    std::map<std::string, Operator*> reg_map_;
};

template <typename Case>
class Register
{
public:
    Register(std::string name)
    {
        printf("Register %s\n", name.c_str());
        Suite::instance()->add(name, new Case());
    }
};

#define OpRegister(Case, name) static Register<Case> __r##Case(name)
#define GetOperator(name) Suite::instance()->find(name)