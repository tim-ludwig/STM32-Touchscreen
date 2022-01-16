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
	Slider::Slider(WORD _x, WORD _y, WORD _width) :
			Slider(_x, _y, _width, 0.0) {

	}

	Slider::Slider(WORD _x, WORD _y, WORD _width, double _pos) :
			Component(_x, _y, _width, radius), position(_pos) {
	}

	double Slider::getPosition() {
		return position;
	}

	void Slider::setPosition(WORD x) {
		double pOld = position;

		position = (x - (box.x() + radius)) / (box.width() - 2.0 * radius);

		if (position < 0)
			position = 0.0;
		else if (position > 1)
			position = 1.0;

		SliderEvent event { *this, pOld, position };
		for (auto& listener : listeners) {
			listener(event);
		}
	}

	void Slider::onEvent(TouchEvent& event) {
		setPosition(event.getX());
	}
	void Slider::onEvent(DragEvent& event) {
		setPosition(event.getX());
	}
	void Slider::onEvent(ReleaseEvent& event) {
		setPosition(event.getX());
	}

	void Slider::addEventListener(std::function<void(SliderEvent&)> listener) {
		listeners.push_back(listener);
	}

	void Slider::show(cDevDisplayGraphic& lcd) {
		WORD x = box.x() + radius, y = box.y() + radius;

		lcd.drawRectangle(x, y - activeHeight / 2, (box.width() - 2 * radius) * position, activeHeight, Color::Blue);
		lcd.drawRectangle(x + (box.width() - 2 * radius) * position, y - inactiveHeight / 2, (box.width() - 2 * radius) * (1 - position), inactiveHeight, Color::Grey);

		lcd.drawCircle(x + (box.width() - 2 * radius) * position, y, radius, Color::DarkGrey);
	}
}
