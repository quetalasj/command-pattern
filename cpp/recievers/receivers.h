#pragma once
#include "string"


class Light {
public:
    std::string name;
    Light(const std::string& name);
    void on();
    void off();
};

class Stereo {
public:
    std::string name;
    Stereo(const std::string& name);
    void on();
    void off();
    void setCD();
    void setVolume(const int& level);
};
