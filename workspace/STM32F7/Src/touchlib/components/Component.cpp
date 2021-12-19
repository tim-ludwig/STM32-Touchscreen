/*
 * Component.cpp
 *
 *  Created on: 16 Dec 2021
 *      Author: TIm Ludwig
 */

#include <touchlib/components/Component.h>

namespace touchlib {
	Component::Component(TouchScreen& _touchScreen, cDevDisplayGraphic& _lcd) :
			Component(_touchScreen, _lcd, 0, 0, 0, 0) {
	}

	Component::Component(TouchScreen& _touchScreen, cDevDisplayGraphic& _lcd,
			int _x, int _y, int _width, int _height) :
			box(_x, _y, _width, _height), touchScreen(_touchScreen), lcd(_lcd) {
		touchScreen.addComponent(this);
	}

	Component::~Component() {
		touchScreen.removeComponent(this);
	}

	BoundingBox& Component::getBoundingBox() {
		return box;
	}
}
