/*
 * ActionEvent.cpp
 *
 *  Created on: 26 Dec 2021
 *      Author: TIm Ludwig
 */

#include <touchlib/events/action/ActionEvent.h>

namespace touchlib {
	ActionEvent::ActionEvent(Component& _target) :
			target(_target) {
	}

	Component& ActionEvent::getTarget() {
		return target;
	}
}
