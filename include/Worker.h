#pragma once

#include <thread>
#include <iostream>

#include "MessageQueue.h"
#include "NotificationService.h"

using namespace std;

class Worker {

private:

    MessageQueue& queue;

    NotificationService* service;

    bool running = true;

public:

    Worker(
        MessageQueue& q,
        NotificationService* s)

        : queue(q),
          service(s) {}

    void start() {

        thread([this]() {

            while(running) {

                string msg = queue.pop();

                if (msg.empty()) {
                    break;
                }

                service->sendNotification(msg);
            }

        }).detach();
    }

    void stop() {
        running = false;
        queue.shutdownQueue();
    }
};