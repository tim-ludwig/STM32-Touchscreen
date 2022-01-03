/*
 * ToggleSwitchEvent.cpp
 *
 *  Created on: 1 Jan 2022
 *      Author: TIm Ludwig
 */

#include <touchlib/events/action/ToggleSwitchEvent.h>

namespace touchlib {
	ToggleSwitchEvent::ToggleSwitchEvent(ToggleSwitch& _switch, bool _state) : ActionEvent(_switch), state(_state) {

	}
}
