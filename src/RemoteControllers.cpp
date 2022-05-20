#include "RemoteControllers.h"
#include "iostream"
#include "sstream"


SimpleRemoteControl::SimpleRemoteControl() {}

void SimpleRemoteControl::setCommand(std::shared_ptr<Command> command) {
    slot = command;
}

void SimpleRemoteControl::buttonWasPressed() {
    slot->execute();
}


RemoteControl::RemoteControl() {
    for (int i=0; i<7; i++) {
        std::shared_ptr<NoCommand> onCmd = std::make_shared<NoCommand>();
        onCommands.push_back(onCmd);
        offCommands.push_back(std::make_shared<NoCommand>());
    }
}

void RemoteControl::setCommand(int slot, const std::shared_ptr<Command> onCommand,
                               const std::shared_ptr<Command> offCommand) {
    onCommands[slot] = onCommand;
    offCommands[slot] = offCommand;
}

void RemoteControl::onButtonWasPushed(int slot) {
    onCommands[slot]->execute();
}

void RemoteControl::offButtonWasPushed(int slot) {
    offCommands[slot]->execute();
}

std::string RemoteControl::toString() {
    std::stringstream stringBuff;
    stringBuff << std::endl << "------ Remote Control ------" << std::endl;
    for (int i=0; i < onCommands.size(); i++) {
        stringBuff << "[slot " << i << " ]" << onCommands[i]->getName() << "         " << offCommands[i]->getName() << std::endl;
    }
    return stringBuff.str();
}

