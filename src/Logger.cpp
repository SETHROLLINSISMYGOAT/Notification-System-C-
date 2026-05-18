#pragma once
#include "Observer.h"

class Logger : public Observer {
public:
    void update(string msg) override {
        cout << "Logging: " << msg << endl;
    }
};