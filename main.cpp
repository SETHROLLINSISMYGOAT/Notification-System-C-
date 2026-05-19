#include <iostream>
#include <thread>
#include <chrono>
#include <memory>

#include "EmailStrategy.h"
#include "NotificationService.h"
#include "Logger.h"
#include "Analytics.h"

#include "MessageQueue.h"
#include "Worker.h"

using namespace std;

int main() {

    // STEP 1: Strategy
    auto emailStrategy =
        make_shared<EmailStrategy>();

    // STEP 2: Notification Service
    NotificationService service(
        emailStrategy);

    // STEP 3: Observers
    Logger logger;
    Analytics analytics;

    service.addObserver(&logger);
    service.addObserver(&analytics);

    // STEP 4: Queue
    MessageQueue queue;

    // STEP 5: Worker
    Worker worker(
        queue,
        &service);

    worker.start();

    // STEP 6: Producer pushes messages
    queue.push("Welcome User");

    queue.push("OTP Sent");

    queue.push("Payment Successful");

    // Allow worker thread to process
    this_thread::sleep_for(
        chrono::seconds(2));

    worker.stop();

    return 0;
}