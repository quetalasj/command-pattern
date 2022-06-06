#include "CeilingFan.h"

#include <utility>
#include "iostream"

CeilingFan::CeilingFan(const std::string&  location): location(location), speed(OFF) {}

void CeilingFan::high() {
    speed = HIGH;
    std::cout << "Speed is " << speed << std::endl;
}

void CeilingFan::medium() {
    speed = MEDIUM;
    std::cout << "Speed is " << speed << std::endl;
}

void CeilingFan::low() {
    speed = LOW;
    std::cout << "Speed is " << speed << std::endl;
}

void CeilingFan::off() {
    speed = OFF;
    std::cout << "Ceiling is off" << std::endl;
}

int CeilingFan::getSpeed() {
    return speed;
}
