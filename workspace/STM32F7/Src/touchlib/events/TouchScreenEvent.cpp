/*
 * TouchScreenEvent.cpp
 *
 *  Created on: 19 Dec 2021
 *      Author: TIm Ludwig
 */

#include <touchlib/events/TouchScreenEvent.h>

namespace touchlib {
	TouchScreenEvent::TouchScreenEvent(WORD _x, WORD _y, WORD _x1, WORD _y1, WORD _touchCount) :
			x(_x), y(_y), x1(_x1), y1(_y1), touchCount(_touchCount) {
	}

	WORD TouchScreenEvent::getTouchCount() {
		return touchCount;
	}
	WORD TouchScreenEvent::getX() {
		return x;
	}
	WORD TouchScreenEvent::getY() {
		return y;
	}
	WORD TouchScreenEvent::getX1() {
		return x1;
	}
	WORD TouchScreenEvent::getY1() {
		return y1;
	}
}
