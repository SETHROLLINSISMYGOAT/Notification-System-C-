#pragma once
#include <iostream>
using namespace std;

class Observer {
public:
    virtual void update(string msg) = 0;
    virtual ~Observer() = default;
};