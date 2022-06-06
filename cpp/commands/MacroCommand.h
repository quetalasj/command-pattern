#pragma once
#include "commands.h"
#include <vector>


class MacroCommand : public Command {
public:
    std::string name = "AllCommands";
    std::vector<std::shared_ptr<Command>> commands;
    MacroCommand(std::vector<std::shared_ptr<Command>> commands);
    void execute() override;
    void undo() override;
    std::string getName() override;
};
