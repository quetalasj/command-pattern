#include "commands.h"

LightOnCommand::LightOnCommand(std::shared_ptr<Light> light) {
    this->light = light;
}

void LightOnCommand::execute() {
    light->on();
}

void LightOnCommand::undo() {
    light->off();
}

std::string LightOnCommand::getName() {
    return this->name;
}


void NoCommand::execute() {}
void NoCommand::undo() {}

std::string NoCommand::getName() {
    return this->name;
}


LightOffCommand::LightOffCommand(std::shared_ptr<Light> light) {
    this->light = light;
}

void LightOffCommand::execute() {
    light->off();
}

void LightOffCommand::undo() {
    light->on();
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

void StereoOnWithCDCommand::undo() {
    stereo->off();
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

void StereoOffWithCDCommand::undo() {
    stereo->on();
}

std::string StereoOffWithCDCommand::getName() {
    return this->name;
}
