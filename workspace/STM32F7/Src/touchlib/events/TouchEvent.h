/*
 * TouchEvent.h
 *
 *  Created on: 17 Dec 2021
 *      Author: TIm Ludwig
 */

#ifndef TOUCHLIB_EVENTS_TOUCHEVENT_H_
#define TOUCHLIB_EVENTS_TOUCHEVENT_H_

#include "TouchScreenEvent.h"

namespace touchlib {
	class TouchEvent: public TouchScreenEvent {
	public:
		TouchEvent(WORD x, WORD y, WORD x1, WORD y1, WORD touchCount);
	};
}

#endif /* TOUCHLIB_EVENTS_TOUCHEVENT_H_ */
