#pragma once
#include "commands.h"
#include "../recievers/CeilingFan.h"

class CeilingFanHighCommand : public Command {
public:
    std::string name = "CeilingFanHighCommand";
    std::shared_ptr<CeilingFan> ceilingFan;
    int prevSpeed;
    CeilingFanHighCommand(std::shared_ptr<CeilingFan> ceilingFan);

    void execute() override;

    void undo() override;
    std::string getName() override;

};

class CeilingFanOffCommand : public Command {
public:
    std::string name = "CeilingFanOffCommand";
    std::shared_ptr<CeilingFan> ceilingFan;
    int prevSpeed;
    CeilingFanOffCommand(std::shared_ptr<CeilingFan> ceilingFan);

    void execute() override;

    void undo() override;
    std::string getName() override;

};

class CeilingFanMediumCommand : public Command {
public:
    std::string name = "CeilingFanmediumCommand";
    std::shared_ptr<CeilingFan> ceilingFan;
    int prevSpeed;
    CeilingFanMediumCommand(std::shared_ptr<CeilingFan> ceilingFan);

    void execute() override;

    void undo() override;
    std::string getName() override;

};