/*
 * ToggleSwitchEvent.h
 *
 *  Created on: 1 Jan 2022
 *      Author: TIm Ludwig
 */

#ifndef TOUCHLIB_EVENTS_ACTION_TOGGLESWITCHEVENT_H_
#define TOUCHLIB_EVENTS_ACTION_TOGGLESWITCHEVENT_H_

#include <touchlib/events/action/ActionEvent.h>
#include <touchlib/components/ToggleSwitch.h>

namespace touchlib {
	class ToggleSwitchEvent: public ActionEvent {
	private:
		bool state;

	public:
		ToggleSwitchEvent(ToggleSwitch&, bool);
	};
}

#endif /* TOUCHLIB_EVENTS_ACTION_TOGGLESWITCHEVENT_H_ */
