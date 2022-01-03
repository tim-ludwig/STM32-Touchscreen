/*
 * BoundingBox.cpp
 *
 *  Created on: 16 Dec 2021
 *      Author: TIm Ludwig
 */

#include <touchlib/BoundingBox.h>

namespace touchlib {
	BoundingBox::BoundingBox(WORD _x, WORD _y, WORD _width, WORD _height) :
			left(_x), top(_y), right(_x + _width), bottom(_y + _height) {
	}

	bool BoundingBox::contains(WORD _x, WORD _y) const {
		return (left <= _x && _x <= right) && (top <= _y && _y <= bottom);
	}

	void BoundingBox::resizeToFit(WORD _x, WORD _y) {
		if (_x < left)
			left = _x;
		else if (_x > right)
			right = _x;

		if (_y < top)
			top = _y;
		else if (_y > bottom)
			bottom = _y;
	}

	void BoundingBox::resizeToFit(BoundingBox const& box) {
		resizeToFit(box.left, box.top);
		resizeToFit(box.right, box.bottom);
	}

	WORD BoundingBox::x() {
		return left;
	}

	WORD BoundingBox::y() {
		return top;
	}

	WORD BoundingBox::width() {
		return right - left;
	}

	WORD BoundingBox::height() {
		return bottom - top;
	}
}
