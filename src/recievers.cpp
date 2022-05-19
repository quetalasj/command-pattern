#include "receivers.h"
#include "iostream"


void LivingRoomLight::on() {
    state = "on";
    std::cout << "Light is " << state << std::endl;
}