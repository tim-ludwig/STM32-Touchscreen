/*
 * DragEvent.cpp
 *
 *  Created on: 17 Dec 2021
 *      Author: TIm Ludwig
 */

#include <touchlib/events/DragEvent.h>

namespace touchlib {
	DragEvent::DragEvent(WORD _x, WORD _xo, WORD _y, WORD _yo, WORD _x1, WORD _x1o, WORD _y1, WORD _y1o, WORD _touchCount) :
			TouchScreenEvent(_x, _y, _x1, _y1, _touchCount), xo(_xo), yo(_yo), x1o(_x1o), y1o(_y1o) {
	}

	WORD DragEvent::getXO() {
		return xo;
	}
	WORD DragEvent::getDX() {
		return x - xo;
	}
	WORD DragEvent::getYO() {
		return yo;
	}
	WORD DragEvent::getDY() {
		return y - yo;
	}
	WORD DragEvent::getX1O() {
		return x1o;
	}
	WORD DragEvent::getDX1() {
		return x1 - x1o;
	}
	WORD DragEvent::getY1O() {
		return y1o;
	}
	WORD DragEvent::getDY1() {
		return y1 - y1o;
	}
}
