#include "receivers.h"
#include "iostream"


Light::Light(const std::string &name) {
    this->name = name;
}

void Light::on() {
    std::cout << "Light in " << name << " is on" << std::endl;
}
void Light::off() {
    std::cout << "Light in " << name << " is off" << std::endl;
}

Stereo::Stereo(const std::string &name) {
    this->name = name;
}

void Stereo::on() {
    std::cout << name << " is on" << std::endl;
}
void Stereo::off() {
    std::cout << name << " is off" << std::endl;
}

void Stereo::setCD() {
    std::cout << name << " is set for CD input" << std::endl;
}

void Stereo::setVolume(const int& level) {
    std::cout << name << " volume set to " << level << std::endl;
}