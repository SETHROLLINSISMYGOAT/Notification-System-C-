# Notification System (C++)

A modular Notification System built in C++ using design patterns to simulate real-world messaging systems like Email, SMS, and Analytics tracking.



## Features

- Multiple notification channels (Email, SMS)
- Strategy Pattern for flexible channel selection
- Observer Pattern for logging and analytics
- Clean and extensible architecture
- Smart pointer-based memory management

---

## Design Patterns Used

### Strategy Pattern
Used to switch notification channels at runtime without changing core logic.

### Observer Pattern
Used to notify multiple systems like Logger and Analytics when an event occurs.

---

## Architecture

Notification-System/
│
├── include/
│   ├── NotificationStrategy.h
│   ├── Observer.h
│   ├── NotificationService.h
│   ├── NotificationObservable.h
│
├── src/
│   ├── EmailStrategy.cpp
│   ├── SMSStrategy.cpp
│   ├── Logger.cpp
│   ├── Analytics.cpp
│   ├── NotificationService.cpp
│
├── main.cpp
├── README.md
├── CMakeLists.txt (optional but good)

---

## ▶ How to Run
 g++ main.cpp -o app
./app

Output
Sending EMAIL: Welcome User
Logging: Welcome User
Analytics Updated: Welcome User

📚 Concepts Used
OOP
Polymorphism
SOLID principles
Design Patterns
Smart pointers

```bash
g++ main.cpp -o app
./app
