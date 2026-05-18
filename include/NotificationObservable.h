#pragma once

#include <vector>
#include <string>
#include "Observer.h"

using namespace std;

class NotificationObservable {
private:
    vector<Observer*> observers;

public:
    void addObserver(Observer* obs) {
        observers.push_back(obs);
    }

    void notifyObservers(string msg) {
        for (auto obs : observers) {
            obs->update(msg);
        }
    }
};