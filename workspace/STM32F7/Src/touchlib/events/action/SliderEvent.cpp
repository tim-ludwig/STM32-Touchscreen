/*
 * SliderEvent.cpp
 *
 *  Created on: 26 Dec 2021
 *      Author: TIm Ludwig
 */

#include <touchlib/events/action/SliderEvent.h>

namespace touchlib {
	SliderEvent::SliderEvent(Slider& _target, double _oldValue, double _newValue) :
			ActionEvent(_target), oldValue(_oldValue), newValue(_newValue) {

	}

	double SliderEvent::getOldValue() {
		return oldValue;
	}

	double SliderEvent::getNewValue() {
		return newValue;
	}
}
