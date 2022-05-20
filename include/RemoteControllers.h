#pragma once
#include "commands.h"
#include "memory"
#include "vector"
#include "string"

class SimpleRemoteControl {
public:
    std::shared_ptr<Command> slot;
    SimpleRemoteControl();
    void setCommand(std::shared_ptr<Command> command);
    void buttonWasPressed();

};


class RemoteControl {
public:
    std::vector<std::shared_ptr<Command>> onCommands;
    std::vector<std::shared_ptr<Command>> offCommands;

    RemoteControl();

    void setCommand(int slot, const std::shared_ptr<Command> onCommand, const std::shared_ptr<Command> offCommand);

    void onButtonWasPushed(int slot);

    void offButtonWasPushed(int slot);

    std::string toString();
};