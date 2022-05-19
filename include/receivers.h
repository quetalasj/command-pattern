#pragma once
#include "string"


class Light {
public:
    std::string state;
    void virtual on() = 0;
};

class LivingRoomLight: public Light {
public:
    void on() override;
};