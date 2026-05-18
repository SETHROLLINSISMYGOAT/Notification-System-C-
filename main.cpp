#include <memory>
#include "EmailStrategy.h"
#include "SMSStrategy.h"
#include "NotificationService.h"
#include "Logger.h"
#include "Analytics.h"

int main() {

    auto emailStrategy = make_shared<EmailStrategy>();

    NotificationService service(emailStrategy);

    Logger logger;
    Analytics analytics;

    service.addObserver(&logger);
    service.addObserver(&analytics);

    service.sendNotification("Welcome User");

    return 0;
}