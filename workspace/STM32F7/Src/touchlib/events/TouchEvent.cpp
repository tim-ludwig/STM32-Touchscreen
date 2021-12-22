/*
 * TouchEvent.cpp
 *
 *  Created on: 17 Dec 2021
 *      Author: TIm Ludwig
 */

#include <touchlib/events/TouchEvent.h>

namespace touchlib {
	TouchEvent::TouchEvent(WORD _x, WORD _y, WORD _x1, WORD _y1, WORD _touchCount) :
			TouchScreenEvent(_x, _y, _x1, _y1, _touchCount) {
	}
}
