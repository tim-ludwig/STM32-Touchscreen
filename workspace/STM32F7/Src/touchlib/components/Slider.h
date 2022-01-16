/*
 * SLider.h
 *
 *  Created on: 16 Dec 2021
 *      Author: TIm Ludwig
 */

#ifndef TOUCHLIB_COMPONENTS_SLIDER_H_
#define TOUCHLIB_COMPONENTS_SLIDER_H_

#include "Component.h"
#include "touchlib/ColorTheme.h"
#include <list>
#include <functional>

namespace touchlib {
	class SliderEvent;

	class Slider: public Component {
	private:
		static const WORD activeHeight = 7, inactiveHeight = 5, radius = 13;

		double position;
		ColorTheme& theme;

		std::list<std::function<void(SliderEvent&)>> listeners;

		void setPosition(WORD x);
	public:
		Slider(WORD x, WORD y, WORD w, ColorTheme&);
		Slider(WORD x, WORD y, WORD w, double pos, ColorTheme&);

		double getPosition();

		void onEvent(TouchEvent&);
		void onEvent(DragEvent&);
		void onEvent(ReleaseEvent&);

		void addEventListener(std::function<void(SliderEvent&)>);

		void show(cDevDisplayGraphic&);
	};
}

#endif /* TOUCHLIB_COMPONENTS_SLIDER_H_ */
