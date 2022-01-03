/*
 * SliderEvent.h
 *
 *  Created on: 26 Dec 2021
 *      Author: TIm Ludwig
 */

#ifndef TOUCHLIB_EVENTS_ACTION_SLIDEREVENT_H_
#define TOUCHLIB_EVENTS_ACTION_SLIDEREVENT_H_

#include "touchlib/events/action/ActionEvent.h"
#include <touchlib/components/Slider.h>

namespace touchlib {
	class SliderEvent: public ActionEvent {
	private:
		double oldValue, newValue;

	public:
		SliderEvent(Slider&, double oldV, double newV);
		double getOldValue();
		double getNewValue();
	};
}

#endif /* TOUCHLIB_EVENTS_ACTION_SLIDEREVENT_H_ */
