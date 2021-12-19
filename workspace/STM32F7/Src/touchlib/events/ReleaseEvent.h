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
	class ReleaseEvent : public TouchScreenEvent {
	public:
		ReleaseEvent(WORD _x, WORD _y, WORD _x1, WORD _y1,
				WORD _touchCount);
	};
}

#endif /* TOUCHLIB_EVENTS_RELEASEEVENT_H_ */
