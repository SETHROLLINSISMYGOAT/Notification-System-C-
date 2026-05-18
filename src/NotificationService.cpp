#pragma once
#include <memory>
#include "NotificationStrategy.h"
#include "NotificationObservable.h"

class NotificationService : public NotificationObservable {

private:
    shared_ptr<NotificationStrategy> strategy;

public:
    NotificationService(shared_ptr<NotificationStrategy> strategy)
        : strategy(strategy) {}

    void sendNotification(string msg) {
        strategy->send(msg);
        notifyObservers(msg);
    }
};