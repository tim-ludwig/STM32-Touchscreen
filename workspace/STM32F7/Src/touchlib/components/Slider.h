/*
 * SLider.h
 *
 *  Created on: 16 Dec 2021
 *      Author: TIm Ludwig
 */

#ifndef TOUCHLIB_COMPONENTS_SLIDER_H_
#define TOUCHLIB_COMPONENTS_SLIDER_H_

#include "Component.h"
#include <list>
#include <functional>

namespace touchlib {
	class SliderEvent;

	class Slider: public Component {
	private:
		WORD radius;
		double position;
		bool horizontal;

		std::list<std::function<void(SliderEvent&)>> listeners;

		void setPosition(WORD x, WORD y);
	public:
		Slider(WORD x, WORD y, WORD w, WORD h, bool horizontal, WORD r, double pos);

		double getPosition();

		void onEvent(TouchEvent&);
		void onEvent(DragEvent&);
		void onEvent(ReleaseEvent&);

		void addEventListener(std::function<void(SliderEvent&)>);

		void show(cDevDisplayGraphic&);
	};
}

#endif /* TOUCHLIB_COMPONENTS_SLIDER_H_ */
