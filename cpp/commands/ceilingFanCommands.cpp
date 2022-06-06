#include "ceilingFanCommands.h"


CeilingFanHighCommand::CeilingFanHighCommand(std::shared_ptr<CeilingFan> ceilingFan) : ceilingFan(ceilingFan), prevSpeed(CeilingFan::OFF) {}


void common_undo( std::shared_ptr<CeilingFan> ceilingFan, const int& prevSpeed ) {
    if (prevSpeed == CeilingFan::HIGH) {
        ceilingFan->high();
    }  else if (prevSpeed == CeilingFan::MEDIUM) {
        ceilingFan->medium();
    } else if (prevSpeed == CeilingFan::LOW) {
        ceilingFan->low();
    } else if (prevSpeed == CeilingFan::OFF) {
        ceilingFan->off();
    }
}

void CeilingFanHighCommand::execute() {
    prevSpeed = ceilingFan->getSpeed();
    ceilingFan->high();
}

void CeilingFanHighCommand::undo() {
    common_undo(ceilingFan, prevSpeed);
}

std::string CeilingFanHighCommand::getName() {
    return this->name;
}


CeilingFanMediumCommand::CeilingFanMediumCommand(std::shared_ptr<CeilingFan> ceilingFan) : ceilingFan(ceilingFan), prevSpeed(CeilingFan::OFF) {}

void CeilingFanMediumCommand::execute() {
    prevSpeed = ceilingFan->getSpeed();
    ceilingFan->medium();
}

void CeilingFanMediumCommand::undo() {
    common_undo(ceilingFan, prevSpeed);
}

std::string CeilingFanMediumCommand::getName() {
    return this->name;
}


CeilingFanOffCommand::CeilingFanOffCommand(std::shared_ptr<CeilingFan> ceilingFan) : ceilingFan(ceilingFan), prevSpeed(CeilingFan::OFF) {}

void CeilingFanOffCommand::execute() {
    prevSpeed = ceilingFan->getSpeed();
    ceilingFan->off();
}

void CeilingFanOffCommand::undo() {
    common_undo(ceilingFan, prevSpeed);
}

std::string CeilingFanOffCommand::getName() {
    return this->name;
}