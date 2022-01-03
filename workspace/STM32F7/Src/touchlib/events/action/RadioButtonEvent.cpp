/*
 * RadioButtonEvent.cpp
 *
 *  Created on: 2 Jan 2022
 *      Author: TIm Ludwig
 */

#include <touchlib/events/action/RadioButtonEvent.h>

namespace touchlib {
	RadioButtonEvent::RadioButtonEvent(RadioButton& _btn, bool _state) : ActionEvent(_btn), state(_state) {

	}

	bool RadioButtonEvent::getState() {
		return state;
	}
}
