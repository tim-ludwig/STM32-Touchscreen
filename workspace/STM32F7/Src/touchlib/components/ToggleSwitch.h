/*
 * ToggleSwitch.h
 *
 *  Created on: 1 Jan 2022
 *      Author: TIm Ludwig
 */

#ifndef TOUCHLIB_COMPONENTS_TOGGLESWITCH_H_
#define TOUCHLIB_COMPONENTS_TOGGLESWITCH_H_

#include <touchlib/components/Component.h>
#include <touchlib/ColorTheme.h>
#include <list>
#include <functional>

namespace touchlib {
	class ToggleSwitchEvent;

	class ToggleSwitch: public Component {
	private:
		static const WORD width = 54, radius = 15, height = 21;

		bool state;
		ColorTheme& theme;

		std::list<std::function<void(ToggleSwitchEvent&)>> listeners;

	public:
		ToggleSwitch(WORD x, WORD y, ColorTheme&);

		bool getState();

		void onEvent(TouchEvent&);
		void onEvent(DragEvent&);
		void onEvent(ReleaseEvent&);

		void addEventListener(std::function<void(ToggleSwitchEvent&)>);

		void show(cDevDisplayGraphic&);
	};
}
#endif /* TOUCHLIB_COMPONENTS_TOGGLESWITCH_H_ */
