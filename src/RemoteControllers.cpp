#include "RemoteControllers.h"

SimpleRemoteControl::SimpleRemoteControl() {}

void SimpleRemoteControl::setCommand(std::shared_ptr<Command> command) {
    slot = command;
}

void SimpleRemoteControl::buttonWasPressed() {
    slot->execute();
}
