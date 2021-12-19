/*
 * TouchScreen.cpp
 *
 *  Created on: 29 Nov 2021
 *      Author: TIm Ludwig
 */

#include <touchlib/TouchScreen.h>
#include "touchlib/components/Component.h"

TouchScreen *TouchScreen::INSTANCE = nullptr;

TouchScreen::TouchScreen(WORD _width, WORD _height,
		cHwI2Cmaster::Device &_i2cTouch) :
		width(_width), height(_height), i2cTouch(_i2cTouch) {
	INSTANCE->~TouchScreen();
	INSTANCE = this;

	touchCount = 0;
}

TouchScreen::TouchScreen(WORD _width, WORD _height,
		cHwI2Cmaster::Device &_i2cTouch, cHwPort_N::PortId _portId, BYTE _pinId) :
		TouchScreen(_width, _height, _i2cTouch) {
	interruptPort = _portId;
	interruptPin = _pinId;

	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

	SYSCFG->EXTICR[interruptPin / 4] |=
			(interruptPort << 4 * (interruptPin % 4));
	EXTI->IMR |= (1 << interruptPin);

	NVIC_EnableIRQ(EXTI15_10_IRQn);

	EXTI->FTSR |= (1 << interruptPin);
	EXTI->RTSR &= ~(1 << interruptPin);
}

TouchScreen::~TouchScreen() {
	INSTANCE = nullptr;
}

void TouchScreen::refresh(void) {
	BYTE data[16];
	i2cTouch.read((BYTE) 0, data, (BYTE) 16);


//	 gestureID = data[GESTURE_ID];

	 touchCount = data[STATUS];
	 if (touchCount == 0xFF)
	 touchCount = 0;

	// this read looks weird, because it is transforming the touchscreen's coordinate
	// system to the lcd's coordinate system.
	x = (((WORD) data[P1_YH] & 0x0F) << 8) | (WORD) data[P1_YL];
	y = height - 1 - ((((WORD) data[P1_XH] & 0x0F) << 8) | (WORD) data[P1_XL]);

	 x1 = (((WORD) data[P2_YH] & 0x0F) << 8) | (WORD) data[P2_YL];
	 y1 = height - 1
	 - ((((WORD) data[P2_XH] & 0x0F) << 8) | (WORD) data[P2_XL]);

}

void TouchScreen::setInterruptMode(bool interrupt) {
	i2cTouch.write((BYTE) MODE, interrupt ? 1 : 0);

	if (interrupt)
		SYSCFG->EXTICR[interruptPin / 4] |= (interruptPort
				<< 4 * (interruptPin % 4));
	else
		SYSCFG->EXTICR[interruptPin / 4] &= ~(interruptPort
				<< 4 * (interruptPin % 4));
}

void TouchScreen::interruptHandler() {
	refresh();
	onTouch();
}

void TouchScreen::onTouch() {
	for (Component* c : components) {
		if (c->getBoundingBox().contains(x, y)) {
			c->onTouch();
		}
	}
}

void TouchScreen::addComponent(Component* c) {
	components.push_back(c);
}

void TouchScreen::removeComponent(Component* c) {
	components.remove(c);
}

WORD TouchScreen::getTouchCount() {
	return touchCount;
}

WORD TouchScreen::getX() {
	return x;
}

WORD TouchScreen::getY() {
	return y;
}

WORD TouchScreen::getX1() {
	return x1;
}

WORD TouchScreen::getY1() {
	return y1;
}

extern "C" {
void EXTI15_10_IRQHandler(void) {
	if (EXTI->PR & (1 << TouchScreen::INSTANCE->interruptPin)) {
		TouchScreen::INSTANCE->interruptHandler();
		EXTI->PR |= (1 << TouchScreen::INSTANCE->interruptPin);
	}
}
}
