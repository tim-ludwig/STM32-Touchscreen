/*
 * TouchScreenEvent.h
 *
 *  Created on: 19 Dec 2021
 *      Author: TIm Ludwig
 */

#ifndef TOUCHLIB_EVENTS_TOUCHSCREENEVENT_H_
#define TOUCHLIB_EVENTS_TOUCHSCREENEVENT_H_

#include "lib.h"

namespace touchlib {
	class TouchScreenEvent {
	protected:
		WORD x, y, x1, y1, touchCount;

	public:
		TouchScreenEvent(WORD x, WORD y, WORD x1, WORD y1, WORD touchCount);

		WORD getTouchCount();
		WORD getX();
		WORD getY();
		WORD getX1();
		WORD getY1();
	};
}

#endif /* TOUCHLIB_EVENTS_TOUCHSCREENEVENT_H_ */
