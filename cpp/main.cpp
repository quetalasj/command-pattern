#include <iostream>
#include "commands.h"
#include "receivers.h"
#include "RemoteControllers.h"
#include "ceilingFanCommands.h"
#include "CeilingFan.h"
#include "MacroCommand.h"

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

class RemoteLoader2 {
public:
    static void main() {
        std::cout << "===========================================" << std::endl;
        RemoteControl remoteControl = RemoteControl();
        std::shared_ptr<CeilingFan> ceilingFan = std::make_shared<CeilingFan>("Living Room");
        CeilingFanHighCommand ceilingFanHigh = CeilingFanHighCommand(ceilingFan);
        CeilingFanMediumCommand ceilingFanMedium = CeilingFanMediumCommand(ceilingFan);
        CeilingFanOffCommand ceilingFanOff = CeilingFanOffCommand(ceilingFan);

        remoteControl.setCommand(0, std::make_shared<CeilingFanHighCommand>(ceilingFanHigh),
                std::make_shared<CeilingFanOffCommand>(ceilingFanOff));

        remoteControl.setCommand(1, std::make_shared<CeilingFanMediumCommand>(ceilingFanMedium),
                                 std::make_shared<CeilingFanOffCommand>(ceilingFanOff));

        std::cout << remoteControl.toString() << std::endl;

        remoteControl.onButtonWasPushed(0);
        remoteControl.offButtonWasPushed(0);
        std::cout << remoteControl.toString() << std::endl;

        remoteControl.undoButtonWasPushed();

        remoteControl.onButtonWasPushed(1);
        std::cout << remoteControl.toString() << std::endl;
        remoteControl.undoButtonWasPushed();

    }
};

class RemoteLoaderMacro {
public:
    static void main() {
        std::cout << "===========================================" << std::endl;
        RemoteControl remoteControl = RemoteControl();
        Light livingRoomLight = Light("Living Room");
        Stereo stereo = Stereo("Living Room");
        std::shared_ptr<CeilingFan> ceilingFan = std::make_shared<CeilingFan>("Living Room");

        std::shared_ptr<LightOnCommand> LightOn = std::make_shared<LightOnCommand>(std::make_shared<Light>(livingRoomLight));
        std::shared_ptr<LightOffCommand> LightOff = std::make_shared<LightOffCommand>(std::make_shared<Light>(livingRoomLight));

        std::shared_ptr<StereoOnWithCDCommand> stereoOn = std::make_shared<StereoOnWithCDCommand>(std::make_shared<Stereo>(stereo));
        std::shared_ptr<StereoOffWithCDCommand> stereoOff = std::make_shared<StereoOffWithCDCommand>(std::make_shared<Stereo>(stereo));

        std::shared_ptr<CeilingFanHighCommand> ceilingFanHigh = std::make_shared<CeilingFanHighCommand>(ceilingFan);
        std::shared_ptr<CeilingFanOffCommand> ceilingFanOff = std::make_shared<CeilingFanOffCommand>(ceilingFan);

        std::vector<std::shared_ptr<Command>> partyOn = {LightOn, stereoOn, ceilingFanHigh};
        std::vector<std::shared_ptr<Command>> partyOff = {LightOff, stereoOff, ceilingFanOff};

        std::shared_ptr<MacroCommand> partyOnMacro = std::make_shared<MacroCommand>(partyOn);
        std::shared_ptr<MacroCommand> partyOffMacro = std::make_shared<MacroCommand>(partyOff);

        remoteControl.setCommand(0, partyOnMacro, partyOffMacro);

        std::cout << remoteControl.toString() << std::endl;

        std::cout << "Pushed Macro On "<< std::endl << std::endl;
        remoteControl.onButtonWasPushed(0);
        std::cout << std::endl << std::endl;


        std::cout << "Pushed Macro Off "<< std::endl << std::endl;
        remoteControl.offButtonWasPushed(0);

    }
};

using namespace std;
int main() {
//    RemoteControlTest::main();
    RemoteLoader::main();
    RemoteLoader2::main();
    RemoteLoaderMacro::main();
    return 0;
}
