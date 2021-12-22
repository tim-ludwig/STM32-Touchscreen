/*
 * Component.cpp
 *
 *  Created on: 16 Dec 2021
 *      Author: TIm Ludwig
 */

#include <touchlib/components/Component.h>

namespace touchlib {
	Component::Component() :
			Component(0, 0, 0, 0) {
	}

	Component::Component(int _x, int _y, int _width, int _height) :
			box(_x, _y, _width, _height) {
	}

	BoundingBox& Component::getBoundingBox() {
		return box;
	}
}
