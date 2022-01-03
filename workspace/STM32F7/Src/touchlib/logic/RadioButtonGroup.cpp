/*
 * RadioButtonGroup.cpp
 *
 *  Created on: 2 Jan 2022
 *      Author: TIm Ludwig
 */

#include <touchlib/logic/RadioButtonGroup.h>
#include <touchlib/components/RadioButton.h>
#include <touchlib/events/action/RadioButtonEvent.h>

namespace touchlib {
	RadioButtonGroup::RadioButtonGroup() {

	}

	void RadioButtonGroup::buttonEventHandler(RadioButtonEvent& event) {
		for (RadioButton* btn : buttons) {
			if (btn == &event.getTarget())
				continue;

			btn->state = false;
		}
	}

	void RadioButtonGroup::addButton(RadioButton* _button) {
		buttons.push_back(_button);
		_button->addEventListener([this](RadioButtonEvent& event) {
			buttonEventHandler(event);
		});
	}
}
