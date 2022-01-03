/*
 * RadioButton.cpp
 *
 *  Created on: 2 Jan 2022
 *      Author: TIm Ludwig
 */

#include <touchlib/components/RadioButton.h>
#include <touchlib/events/action/RadioButtonEvent.h>
#include <Color.h>

namespace touchlib {
	RadioButton::RadioButton(WORD _x, WORD _y) :
			RadioButton(_x, _y, false) {

	}

	RadioButton::RadioButton(WORD _x, WORD _y, bool _deselectable) :
			Component(_x, _y, 28, 28), deselectable(_deselectable), state(false) {

	}

	bool RadioButton::getState() {
		return state;
	}

	void RadioButton::onEvent(TouchEvent&) {
		if (state && !deselectable)
			return;

		state = !state;

		RadioButtonEvent event { *this, state };
		for (auto& listener : listeners) {
			listener(event);
		}
	}

	void RadioButton::onEvent(DragEvent&) {
	}
	void RadioButton::onEvent(ReleaseEvent&) {
	}

	void RadioButton::addEventListener(std::function<void(RadioButtonEvent&)> listener) {
		listeners.push_back(listener);
	}

	void RadioButton::show(cDevDisplayGraphic& lcd) {
		lcd.drawCircle(box.x() + 14, box.y() + 14, 14, Color::Grey);

		if (state)
			lcd.drawCircle(box.x() + 14, box.y() + 14, 9, Color::DarkGrey);
	}
}
