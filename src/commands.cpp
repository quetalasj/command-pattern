#include "commands.h"

LightOnCommand::LightOnCommand(std::shared_ptr<Light> light) {
    this->light = light;
}

void LightOnCommand::execute() {
    light->on();
}

std::string LightOnCommand::getName() {
    return this->name;
}

void NoCommand::execute() {}

std::string NoCommand::getName() {
    return this->name;
}

LightOffCommand::LightOffCommand(std::shared_ptr<Light> light) {
    this->light = light;
}

void LightOffCommand::execute() {
    light->off();
}

std::string LightOffCommand::getName() {
    return this->name;
}


StereoOnWithCDCommand::StereoOnWithCDCommand(std::shared_ptr<Stereo> stereo) {
    this->stereo = stereo;
}

void StereoOnWithCDCommand::execute() {
    stereo->on();
}

std::string StereoOnWithCDCommand::getName() {
    return this->name;
}

StereoOffWithCDCommand::StereoOffWithCDCommand(std::shared_ptr<Stereo> stereo) {
    this->stereo = stereo;
}

void StereoOffWithCDCommand::execute() {
    stereo->off();
}

std::string StereoOffWithCDCommand::getName() {
    return this->name;
}