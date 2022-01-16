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
	RadioButton::RadioButton(WORD _x, WORD _y, ColorTheme& _theme) :
			RadioButton(_x, _y, false, _theme) {

	}

	RadioButton::RadioButton(WORD _x, WORD _y, bool _deselectable, ColorTheme& _theme) :
			Component(_x, _y, 2 * radius, 2 * radius), deselectable(_deselectable), state(false), theme(_theme) {

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
		lcd.drawCircle(box.x() + radius, box.y() + radius, radius, state ? theme.primary : Color::DarkGrey);
		lcd.drawCircle(box.x() + radius, box.y() + radius, radius - 3, state ? theme.lightPrimary : Color::Grey);

		if (state)
			lcd.drawCircle(box.x() + radius, box.y() + radius, radius / 2, theme.primary);
	}
}
