/*
 * RadioButtonEvent.h
 *
 *  Created on: 2 Jan 2022
 *      Author: TIm Ludwig
 */

#ifndef TOUCHLIB_EVENTS_ACTION_RADIOBUTTONEVENT_H_
#define TOUCHLIB_EVENTS_ACTION_RADIOBUTTONEVENT_H_

#include <touchlib/events/action/ActionEvent.h>
#include <touchlib/components/RadioButton.h>

namespace touchlib {
	class RadioButtonEvent: public ActionEvent {
	private:
		bool state;

	public:
		RadioButtonEvent(RadioButton&, bool);

		bool getState();
	};
}

#endif /* TOUCHLIB_EVENTS_ACTION_RADIOBUTTONEVENT_H_ */
