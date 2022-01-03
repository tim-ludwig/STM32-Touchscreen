/*
 * RadioButtonGroup.h
 *
 *  Created on: 2 Jan 2022
 *      Author: TIm Ludwig
 */

#ifndef TOUCHLIB_LOGIC_RADIOBUTTONGROUP_H_
#define TOUCHLIB_LOGIC_RADIOBUTTONGROUP_H_

#include <list>

namespace touchlib {
	class RadioButton;
	class RadioButtonEvent;

	class RadioButtonGroup {
	private:
		std::list<RadioButton*> buttons;

	public:
		RadioButtonGroup();

		void buttonEventHandler(RadioButtonEvent&);
		void addButton(RadioButton*);
	};
}
#endif /* TOUCHLIB_LOGIC_RADIOBUTTONGROUP_H_ */
