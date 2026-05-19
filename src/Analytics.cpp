#include "Observer.h"

class Analytics : public Observer {
public:
    void update(string msg) override {
        cout << "Analytics Updated: " << msg << endl;
    }
};