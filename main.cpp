#include <iostream>
#include "commands.h"
#include "receivers.h"
#include "RemoteControllers.h"

class RemoteControlTest {
public:
    static void main() {
        SimpleRemoteControl remote = SimpleRemoteControl();
        LivingRoomLight light = LivingRoomLight();

        LightOnCommand lightOn = LightOnCommand(std::make_shared<LivingRoomLight>(light));
        remote.setCommand(std::make_shared<LightOnCommand>(lightOn));
        remote.buttonWasPressed();
    }
};

using namespace std;
int main() {
    RemoteControlTest::main();

    return 0;
}
