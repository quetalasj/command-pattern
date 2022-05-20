#include <iostream>
#include "commands.h"
#include "receivers.h"
#include "RemoteControllers.h"

class RemoteControlTest {
public:
    static void main() {
        SimpleRemoteControl remote = SimpleRemoteControl();
        std::shared_ptr<Light> light = std::make_shared<Light>("Living Room");

        LightOnCommand lightOn = LightOnCommand(light);
        remote.setCommand(std::make_shared<LightOnCommand>(lightOn));
        remote.buttonWasPressed();
    }
};

class RemoteLoader {
public:
    static void main() {
        RemoteControl remoteControl = RemoteControl();
        Light livingRoomLight = Light("Living Room");
        Light kitchenLight = Light("Kitchen");
        Stereo stereo = Stereo("Living Room");

        std::shared_ptr<LightOnCommand> livingRooLightOn = std::make_shared<LightOnCommand>(std::make_shared<Light>(livingRoomLight));
        std::shared_ptr<LightOffCommand> livingRooLightOff = std::make_shared<LightOffCommand>(std::make_shared<Light>(livingRoomLight));

        std::shared_ptr<LightOnCommand> kitchenLightOn = std::make_shared<LightOnCommand>(std::make_shared<Light>(kitchenLight));
        std::shared_ptr<LightOffCommand> kitchenLightOff = std::make_shared<LightOffCommand>(std::make_shared<Light>(kitchenLight));

        std::shared_ptr<StereoOnWithCDCommand> stereoOn = std::make_shared<StereoOnWithCDCommand>(std::make_shared<Stereo>(stereo));
        std::shared_ptr<StereoOffWithCDCommand> stereoOff = std::make_shared<StereoOffWithCDCommand>(std::make_shared<Stereo>(stereo));

        remoteControl.setCommand(0, livingRooLightOn, livingRooLightOff);
        remoteControl.setCommand(1, kitchenLightOn, kitchenLightOff);
        remoteControl.setCommand(2, stereoOn, stereoOff);

        std::cout << remoteControl.toString() << std::endl;

        remoteControl.onButtonWasPushed(0);
        remoteControl.offButtonWasPushed(0);
        std::cout << remoteControl.toString() << std::endl;
        remoteControl.undoButtonWasPushed();
        remoteControl.offButtonWasPushed(0);
        remoteControl.onButtonWasPushed(0);
        std::cout << remoteControl.toString() << std::endl;

        remoteControl.onButtonWasPushed(1);
        remoteControl.offButtonWasPushed(1);

        std::cout << remoteControl.toString() << std::endl;

        remoteControl.onButtonWasPushed(2);
        remoteControl.offButtonWasPushed(2);
        remoteControl.undoButtonWasPushed();
        std::cout << remoteControl.toString() << std::endl;
    }
};

using namespace std;
int main() {
//    RemoteControlTest::main();
    RemoteLoader::main();
    return 0;
}
