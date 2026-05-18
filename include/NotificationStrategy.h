#pragma once
#include <iostream>
using namespace std;
class NotificationStrategy{
public:
    virtual void send(string msg)=0;
    virtual ~NotificationStrategy()=default;
};