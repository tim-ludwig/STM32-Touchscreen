/*
 * BoundingBox.cpp
 *
 *  Created on: 16 Dec 2021
 *      Author: TIm Ludwig
 */

#include <touchlib/BoundingBox.h>

namespace touchlib {
	BoundingBox::BoundingBox(int _x, int _y, int _width, int _height) :
			x(_x), y(_y), width(_width), height(_height) {
	}

	bool BoundingBox::contains(int _x, int _y) {
		return (x <= _x && _x < x + width) && (y <= _y && _y <= y + height);
	}
}
