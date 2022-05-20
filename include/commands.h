#pragma once
#include "memory"
#include "receivers.h"
#include "string"

class Command {
public:
    std::string name = "default";
    void virtual execute() = 0;
    void virtual undo() = 0;
    std::string virtual getName() = 0;
};

class LightOnCommand: public Command {
public:
    std::string name = "LightOnCommand";
    std::shared_ptr<Light> light;
    LightOnCommand(std::shared_ptr<Light> light);
    void execute() override;
    void undo() override;
    std::string getName() override;
};

class NoCommand: public Command {
public:
    std::string name = "NoCommand";
    void execute() override;
    void undo() override;
    std::string getName() override;
};

class LightOffCommand: public Command {
public:
    std::string name = "LightOffCommand";
    std::shared_ptr<Light> light;
    LightOffCommand(std::shared_ptr<Light> light);
    void execute() override;
    void undo() override;
    std::string getName() override;
};

class StereoOnWithCDCommand: public Command {
public:
    std::string name = "StereoOnWithCDCommand";
    std::shared_ptr<Stereo> stereo;
    StereoOnWithCDCommand(std::shared_ptr<Stereo> stereo);
    void execute() override;
    void undo() override;
    std::string getName() override;
};

class StereoOffWithCDCommand: public Command {
public:
    std::string name = "StereoOffWithCDCommand";
    std::shared_ptr<Stereo> stereo;
    StereoOffWithCDCommand(std::shared_ptr<Stereo> stereo);
    void execute() override;
    void undo() override;
    std::string getName() override;
};