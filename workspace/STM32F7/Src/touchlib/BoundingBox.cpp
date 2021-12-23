/*
 * BoundingBox.cpp
 *
 *  Created on: 16 Dec 2021
 *      Author: TIm Ludwig
 */

#include <touchlib/BoundingBox.h>

namespace touchlib {
	BoundingBox::BoundingBox(int _x, int _y, int _width, int _height) :
			left(_x), top(_y), right(_x + _width), bottom(_y + _height) {
	}

	bool BoundingBox::contains(int _x, int _y) const {
		return (left <= _x && _x <= right) && (top <= _y && _y <= bottom);
	}

	void BoundingBox::resizeToFit(int _x, int _y) {
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

	int BoundingBox::x() {
		return left;
	}

	int BoundingBox::y() {
		return top;
	}

	int BoundingBox::width() {
		return right - left;
	}

	int BoundingBox::height() {
		return bottom - top;
	}
}
