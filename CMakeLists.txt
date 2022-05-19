cmake_minimum_required(VERSION 3.22)
project(command_pattern)

set(CMAKE_CXX_STANDARD 20)
include_directories(include)
add_executable(command_pattern main.cpp src/commands.cpp src/recievers.cpp src/RemoteControllers.cpp)
