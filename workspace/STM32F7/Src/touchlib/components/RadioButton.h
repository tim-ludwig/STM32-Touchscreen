/*
 * RadioButton.h
 *
 *  Created on: 2 Jan 2022
 *      Author: TIm Ludwig
 */

#ifndef TOUCHLIB_COMPONENTS_RADIOBUTTON_H_
#define TOUCHLIB_COMPONENTS_RADIOBUTTON_H_

#include <touchlib/components/Component.h>
#include <touchlib/logic/RadioButtonGroup.h>
#include <functional>
#include <vector>

namespace touchlib {
	class RadioButtonEvent;

	class RadioButton: public Component {
	private:
		bool state, deselectable;

		std::vector<std::function<void(RadioButtonEvent&)>> listeners;

	public:
		RadioButton(WORD x, WORD y);
		RadioButton(WORD x, WORD y, bool);

		bool getState();

		void onEvent(TouchEvent&);
		void onEvent(DragEvent&);
		void onEvent(ReleaseEvent&);

		void addEventListener(std::function<void(RadioButtonEvent&)>);

		void show(cDevDisplayGraphic&);

		friend void RadioButtonGroup::buttonEventHandler(RadioButtonEvent&);
	};
}

#endif /* TOUCHLIB_COMPONENTS_RADIOBUTTON_H_ */
