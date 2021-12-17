#ifndef TOUCHSCREEN_H_
#define TOUCHSCREEN_H_

#include "lib.h"
#include <vector>

class Component;

class TouchScreen {
private:
	// https://github.com/ryankurte/stm32-base/blob/master/drivers/BSP/Components/ft6x06/ft6x06.h
	typedef enum reg {
		MODE = 0x00,
		GESTURE_ID,
		STATUS,
		P1_XH,
		P1_XL,
		P1_YH,
		P1_YL,
		P1_WEIGHT,
		P1_AREA,
		P2_XH,
		P2_XL,
		P2_YH,
		P2_YL,
		P2_WEIGHT,
		P2_AREA,
		TH_GRP = 0x80,
		TH_DIFF = 0x85,
		CTRL,
		TIME_ENTER_MONITOR,
		PERIOD_ACTIVE,
		PERIOD_MONITOR,
		RADIAN_VALUE = 0x91,
		OFFSET_LR,
		OFFSET_UD,
		DIST_LR,
		DIST_UD,
		DIST_ZOOM,
		LIB_VER_H = 0xA1,
		LIB_VER_L,
		CIPHER,
		IT_MODE,
		PWR_MODE,
		FIRM_ID,
		CHIP_ID = 0xA8,
		RLEASE_CODE_ID = 0xAF,
		STATE = 0xBC
	} REG;

	WORD x, y, x1, y1, touchCount;
	const WORD width;
	const WORD height;

	cHwI2Cmaster::Device &i2cTouch;
	cHwPort_N::PortId interruptPort;

	std::vector<Component*> components;

public:
	BYTE interruptPin;
	static TouchScreen *INSTANCE;

	TouchScreen(WORD w, WORD h, cHwI2Cmaster::Device&);
	TouchScreen(WORD w, WORD h, cHwI2Cmaster::Device&, cHwPort_N::PortId portId,
			BYTE pinId);
	~TouchScreen();

	WORD getWidth();
	WORD getHeight();

	void refresh(void);
	void setInterruptMode(bool);
	void interruptHandler(void);

	void onTouch(void);
	void addComponent(Component*);

	WORD getTouchCount();
	WORD getX();
	WORD getY();
	WORD getX1();
	WORD getY1();
};
#endif /* TOUCHSCREEN_H_ */
