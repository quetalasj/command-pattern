#include "MacroCommand.h"


MacroCommand::MacroCommand(std::vector<std::shared_ptr<Command>> commands) : commands(commands) {}

void MacroCommand::execute() {
    for (auto command : commands) {
        command->execute();
    }
}

void MacroCommand::undo() {
    for (auto command : commands) {
        command->undo();
    }
}
std::string MacroCommand::getName() {
    return this->name;
}
