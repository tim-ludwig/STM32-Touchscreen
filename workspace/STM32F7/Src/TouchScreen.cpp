/*
 * TouchScreen.cpp
 *
 *  Created on: 29 Nov 2021
 *      Author: TIm Ludwig
 */

#include <TouchScreen.h>

TouchScreen::TouchScreen(cHwI2Cmaster::Device _i2cTouch) :
		i2cTouch(_i2cTouch) {
}

void TouchScreen::refresh(void) {
	BYTE data[16];
	i2cTouch.read((BYTE) 0, data, (BYTE) 16);

	touchCount = data[2];
	if(touchCount == 0xFF) touchCount = 0;
	retainedCount = 0;
	if ((data[3] & 0xF0) == 0x40)
		retainedCount++;
	if ((data[11] & 0xF0) == 0x40)
		retainedCount++;

	x0 = (((WORD) data[5] & 0x0F) << 8) | (WORD) data[6];
	y0 = (((WORD) data[3] & 0x0F) << 8) | (WORD) data[4];

	x1 = (((WORD) data[11] & 0x0F) << 8) | (WORD) data[12];
	y1 = (((WORD) data[9] & 0x0F) << 8) | (WORD) data[10];
}

BYTE TouchScreen::getTouchCount() {
	return touchCount;
}

BYTE TouchScreen::getRetainedCount() {
	return retainedCount;
}

WORD TouchScreen::getX0() {
	return x0;
}

WORD TouchScreen::getY0() {
	return y0;
}

WORD TouchScreen::getX1() {
	return x1;
}
WORD TouchScreen::getY1() {
	return y1;
}
