cmake_minimum_required(VERSION 3.12)
project(command_pattern)

set(CMAKE_CXX_STANDARD 17)

include_directories(commands controllers recievers)

set(SOURCES
        main.cpp
        commands/commands.cpp
        commands/ceilingFanCommands.cpp
        recievers/recievers.cpp
        controllers/RemoteControllers.cpp
        recievers/CeilingFan.cpp)

add_executable(command_pattern ${SOURCES})
