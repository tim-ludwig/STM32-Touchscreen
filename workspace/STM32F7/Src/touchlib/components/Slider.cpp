/*
 * SLider.cpp
 *
 *  Created on: 16 Dec 2021
 *      Author: TIm Ludwig
 */

#include <touchlib/components/Slider.h>
#include <touchlib/events/action/SliderEvent.h>
#include "Color.h"

namespace touchlib {
	Slider::Slider(WORD _x, WORD _y, WORD _width, WORD _height, bool _horizontal, WORD _r, double _pos) :
			Component(_x, _y, _width, _height), horizontal(_horizontal), radius(_r), position(_pos) {
	}

	double Slider::getPosition() {
		return position;
	}

	void Slider::setPosition(WORD x, WORD y) {
		double pOld = position;

		position = horizontal ? (x - (box.x() + radius)) / (box.width() - 2.0 * radius) : (y - (box.y() + radius)) / (box.height() - 2.0 * radius);

		if (position < 0)
			position = 0.0;
		else if (position > 1)
			position = 1.0;

		SliderEvent event{*this, pOld, position};
		for(auto& listener : listeners) {
			listener(event);
		}
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

	void Slider::addEventListener(std::function<void(SliderEvent&)> listener) {
		listeners.push_back(listener);
	}

	void Slider::show(cDevDisplayGraphic& lcd) {
		WORD x = box.x() + radius, y = box.y() + radius;

		if(horizontal) {
			lcd.drawRectangle(x - 1, y - 1, box.width() - 2 * radius + 2, 2, Color::Grey);
			x += (box.width() - 2 * radius) * position;
		} else {
			lcd.drawRectangle(x - 1, y - 1, 2, box.height() - 2 * radius + 2, Color::Grey);
			y += (box.height() - 2 * radius) * position;
		}

		lcd.drawCircle(x, y, radius, Color::DarkGrey);
	}
}
