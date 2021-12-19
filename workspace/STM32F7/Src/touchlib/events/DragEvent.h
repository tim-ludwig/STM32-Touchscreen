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
		DragEvent(WORD _x, WORD _xo, WORD _y, WORD _yo, WORD _x1, WORD _x1o,
				WORD _y1, WORD _y1o, WORD _touchCount);

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

#endif /* TOUCHLIB_EVENTS_DRAGEVENT_H_ */
