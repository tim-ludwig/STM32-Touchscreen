/*
 * Component.cpp
 *
 *  Created on: 16 Dec 2021
 *      Author: TIm Ludwig
 */

#include <touchlib/components/Component.h>
#include <touchlib/events/action/ActionEvent.h>

namespace touchlib {
	Component::Component() :
			Component(0, 0, 0, 0) {
	}

	Component::Component(WORD _x, WORD _y, WORD _width, WORD _height) :
			box(_x, _y, _width, _height) {
	}

	BoundingBox& Component::getBoundingBox() {
		return box;
	}
}
