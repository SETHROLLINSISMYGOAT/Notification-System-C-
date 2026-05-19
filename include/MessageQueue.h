#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>
#include <string>

using namespace std;

class MessageQueue {

private:
    queue<string> q;
    mutex mtx;
    condition_variable cv;
    bool shutdown = false;

public:

    void push(const string& msg) {

        unique_lock<mutex> lock(mtx);

        q.push(msg);

        cv.notify_one();
    }

    string pop() {

        unique_lock<mutex> lock(mtx);

        cv.wait(lock, [&] {
            return !q.empty() || shutdown;
        });

        if (shutdown && q.empty()) {
            return "";
        }

        string msg = q.front();

        q.pop();

        return msg;
    }

    void shutdownQueue() {
        unique_lock<mutex> lock(mtx);
        shutdown = true;
        cv.notify_all();
    }
};