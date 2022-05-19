#include "commands.h"

LightOnCommand::LightOnCommand(std::shared_ptr<Light> light) {
    this->light = light;
}

void LightOnCommand::execute() {
    light->on();
}