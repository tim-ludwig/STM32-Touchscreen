#ifndef TOUCHSCREEN_H_
#define TOUCHSCREEN_H_

#include "lib.h"

class TouchScreen {
private:
	BYTE touchCount;
	BYTE retainedCount;
	WORD x0, y0, x1, y1;
	cHwI2Cmaster::Device i2cTouch;

public:
	TouchScreen(cHwI2Cmaster::Device);

	void refresh(void);
	BYTE getTouchCount();
	BYTE getRetainedCount();
	WORD getX0();
	WORD getY0();
	WORD getX1();
	WORD getY1();
};

#endif /* TOUCHSCREEN_H_ */
