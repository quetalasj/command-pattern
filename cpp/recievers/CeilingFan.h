#pragma once
#include <string>

class CeilingFan {
public:
    const static int HIGH = 3;
    const static int MEDIUM = 2;
    const static int LOW = 1;
    const static int OFF = 0;
    std::string location;
    int speed;

    CeilingFan(const std::string&  location);
    void high();
    void medium();
    void low();
    void off();
    int getSpeed();
};
