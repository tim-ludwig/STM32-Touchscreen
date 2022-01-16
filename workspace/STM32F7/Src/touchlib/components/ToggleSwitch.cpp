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
	ToggleSwitch::ToggleSwitch(WORD _x, WORD _y, ColorTheme& _theme) :
			Component(_x, _y, width, 2 * radius), state(false), theme(_theme) {

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
		lcd.drawRectangle(box.x() + radius, box.y() + radius - height/2, width - height, height, state ? theme.lightPrimary : Color::Grey);
		lcd.drawCircle(box.x() + radius, box.y() + radius, height/2, state ? theme.lightPrimary : Color::Grey);
		lcd.drawCircle(box.x() + radius + width - height, box.y() + radius, height/2, state ? theme.lightPrimary : Color::Grey);

		if(state) lcd.drawCircle(box.x() + radius + width - height, box.y() + radius, radius, theme.primary);
		else lcd.drawCircle(box.x() + radius, box.y() + radius, radius, Color::DarkGrey);
	}
}
