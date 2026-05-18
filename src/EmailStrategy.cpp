#pragma once
#include "NotificationStrategy.h"
class EmailStrategy : public NotificationStrategy{
public:
    void send (string msg) override {
    cout << "Sending EMAIL: " << msg << endl;

    }
};
