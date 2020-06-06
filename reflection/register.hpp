#pragma once
#include <string>
#include <map>
#include "factory.hpp"

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
    void add(const std::string& name, Factory* p)
    {
        reg_map_[name] = p;
    }

    Factory* find(const std::string& name)
    {
        Factory* p = NULL;
        if (reg_map_.find(name) != reg_map_.end())
        {
            p = reg_map_[name];
        }
        return p;
    }
private:
    std::map<std::string, Factory*> reg_map_;
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

#define OpFactoryRegister(Case, name) static Register<Case> __r##Case(name)
#define GetOperator(name) Suite::instance()->find(name)->create()