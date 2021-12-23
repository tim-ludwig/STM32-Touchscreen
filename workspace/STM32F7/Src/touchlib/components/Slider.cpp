/*
 * SLider.cpp
 *
 *  Created on: 16 Dec 2021
 *      Author: TIm Ludwig
 */

#include <touchlib/components/Slider.h>
#include "Color.h"

namespace touchlib {
	Slider::Slider(int _x, int _y, int _width, int _height, bool _horizontal, int _r, double _pos) :
			Component(_x, _y, _width, _height), horizontal(_horizontal), radius(_r), position(_pos) {
	}

	double Slider::getPosition() {
		return position;
	}

	void Slider::setPosition(WORD x, WORD y) {
		position = horizontal ? (x - (box.x() + radius)) / (box.width() - 2.0 * radius) : (y - (box.y() + radius)) / (box.height() - 2.0 * radius);

		if (position < 0)
			position = 0.0;
		else if (position > 1)
			position = 1.0;
	}

	void Slider::onEvent(TouchEvent& event) {
		setPosition(event.getX(), event.getY());
	}
	void Slider::onEvent(DragEvent& event) {
		setPosition(event.getX(), event.getY());
	}
	void Slider::onEvent(ReleaseEvent& event) {
		setPosition(event.getX(), event.getY());
	}

	void Slider::show(cDevDisplayGraphic& lcd) {
		int x = box.x() + radius, y = box.y() + radius;

		if(horizontal) {
			lcd.drawRectangle(x - 1, y - 1, box.width() - 2 * radius + 2, 2, Color::Black);
			x += (box.width() - 2 * radius) * position;
		} else {
			lcd.drawRectangle(x - 1, y - 1, 2, box.height() - 2 * radius + 2, Color::Black);
			y += (box.height() - 2 * radius) * position;
		}

		lcd.drawCircle(x, y, radius, Color::Black);
		lcd.drawCircle(x, y, radius - 2, Color::White);
	}
}
