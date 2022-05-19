#pragma once
#include "commands.h"
#include "memory"

class SimpleRemoteControl {
public:
    std::shared_ptr<Command> slot;
    SimpleRemoteControl();
    void setCommand(std::shared_ptr<Command> command);
    void buttonWasPressed();

};