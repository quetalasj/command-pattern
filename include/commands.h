#pragma once
#include "memory"
#include "receivers.h"


class Command {
public:
    void virtual execute() = 0;
};

class LightOnCommand: public Command {
public:
    std::shared_ptr<Light> light;
    LightOnCommand(std::shared_ptr<Light> light);
    void execute() override;
};