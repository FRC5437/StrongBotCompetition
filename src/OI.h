

#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	std::shared_ptr<Joystick> joy3;
	std::shared_ptr<JoystickButton> b3_3;
	std::shared_ptr<JoystickButton> b3_2;
	std::shared_ptr<JoystickButton> b3_1;
	std::shared_ptr<JoystickButton> b3_8;
	std::shared_ptr<Joystick> joy2;
	std::shared_ptr<JoystickButton> b2_4;
	std::shared_ptr<JoystickButton> b2_1;
	std::shared_ptr<Joystick> joy1;
	std::shared_ptr<JoystickButton> b1_1;
	std::shared_ptr<JoystickButton> b3_4;
	std::shared_ptr<JoystickButton> b1_3;
	std::shared_ptr<JoystickButton> b2_3;
	std::shared_ptr<JoystickButton>	b3_5;
	std::shared_ptr<JoystickButton>	b3_6;
	std::shared_ptr<JoystickButton>	b3_7;
	std::shared_ptr<JoystickButton>	b2_7;
	std::shared_ptr<JoystickButton>	b2_8;

public:
	OI();


	std::shared_ptr<Joystick> getjoy1();
	std::shared_ptr<Joystick> getjoy2();
	std::shared_ptr<Joystick> getjoy3();
};

#endif
