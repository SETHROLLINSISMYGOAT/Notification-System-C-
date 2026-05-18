#pragma once
#include "NotificationStrategy.h"
class SMSStrategy : public NotificationStrategy {
public:
    void send(string msg) override {
        cout << "Sending SMS : " << msg << endl;
    }
};