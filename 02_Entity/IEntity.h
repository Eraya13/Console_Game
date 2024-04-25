#pragma once
#include <iostream>

class IEntity {
public:
    virtual std::string getName() const = 0;
};