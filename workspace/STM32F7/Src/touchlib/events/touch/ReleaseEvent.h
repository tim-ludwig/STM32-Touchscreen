/*
 * ReleaseEvent.h
 *
 *  Created on: 17 Dec 2021
 *      Author: TIm Ludwig
 */

#ifndef TOUCHLIB_EVENTS_RELEASEEVENT_H_
#define TOUCHLIB_EVENTS_RELEASEEVENT_H_

#include "TouchScreenEvent.h"

namespace touchlib {
	class ReleaseEvent: public TouchScreenEvent {
	public:
		ReleaseEvent(WORD x, WORD y, WORD x1, WORD y1, WORD touchCount);
	};
}

#endif /* TOUCHLIB_EVENTS_TOUCH_RELEASEEVENT_H_ */
