/*
 * DragEvent.h
 *
 *  Created on: 17 Dec 2021
 *      Author: TIm Ludwig
 */

#ifndef TOUCHLIB_EVENTS_DRAGEVENT_H_
#define TOUCHLIB_EVENTS_DRAGEVENT_H_

#include "TouchScreenEvent.h"

namespace touchlib {
	class DragEvent: public TouchScreenEvent {
	private:
		WORD xo, yo, x1o, y1o;
	public:
		DragEvent(WORD x, WORD xo, WORD y, WORD yo, WORD x1, WORD x1o, WORD y1, WORD y1o, WORD touchCount);

		WORD getXO();
		WORD getDX();
		WORD getYO();
		WORD getDY();
		WORD getX1O();
		WORD getDX1();
		WORD getY1O();
		WORD getDY1();
	};
}

#endif /* TOUCHLIB_EVENTS_TOUCH_DRAGEVENT_H_ */
