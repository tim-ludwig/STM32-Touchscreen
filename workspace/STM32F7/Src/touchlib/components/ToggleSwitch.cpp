/*
 * ToggleSwitch.cpp
 *
 *  Created on: 1 Jan 2022
 *      Author: TIm Ludwig
 */

#include <touchlib/components/ToggleSwitch.h>
#include <touchlib/events/action/ToggleSwitchEvent.h>
#include <Color.h>

namespace touchlib {
	ToggleSwitch::ToggleSwitch(WORD _x, WORD _y) :
			ToggleSwitch(_x, _y, Color::Blue) {

	}

	ToggleSwitch::ToggleSwitch(WORD _x, WORD _y, WORD _colorActive) : ToggleSwitch(_x, _y, _colorActive, Color::Grey, Color::DarkGrey) {}

	ToggleSwitch::ToggleSwitch(WORD _x, WORD _y, WORD _colorActive, WORD _colorInactive, WORD _colorHandle) :
			Component(_x, _y, 60, 30), state(false), colorActive(_colorActive), colorInactive(_colorInactive), colorHandle(_colorHandle) {

	}

	void ToggleSwitch::addEventListener(std::function<void(ToggleSwitchEvent&)> listener) {
		listeners.push_back(listener);
	}

	void ToggleSwitch::onEvent(TouchEvent&) {
		state = !state;

		ToggleSwitchEvent event { *this, state };
		for (auto& listener : listeners) {
			listener(event);
		}
	}

	void ToggleSwitch::onEvent(DragEvent&) {
	}
	void ToggleSwitch::onEvent(ReleaseEvent&) {
	}

	void ToggleSwitch::show(cDevDisplayGraphic& lcd) {
		lcd.drawRectangle(box.x() + 15, box.y(), box.width() - 30, box.height(), state ? colorActive : colorInactive);
		lcd.drawCircle(box.x() + 15, box.y() + 15, 15, state ? colorActive : colorHandle);
		lcd.drawCircle(box.x() + box.width() - 15, box.y() + 15, 15, state ? colorHandle : colorInactive);
	}
}
