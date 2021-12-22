/*
 * SLider.h
 *
 *  Created on: 16 Dec 2021
 *      Author: TIm Ludwig
 */

#ifndef TOUCHLIB_COMPONENTS_SLIDER_H_
#define TOUCHLIB_COMPONENTS_SLIDER_H_

#include "Component.h"

namespace touchlib {
	class Slider: public Component {
	private:
		int radius;
		double position;
		bool horizontal;

		void setPosition(WORD x, WORD y);
	public:
		Slider(int _x, int _y, int _width, int _height, bool _horizontal, int _r, double pos);

		double getPosition();

		void onEvent(TouchEvent&);
		void onEvent(DragEvent&);
		void onEvent(ReleaseEvent&);

		void show(cDevDisplayGraphic&);
	};
}

#endif /* TOUCHLIB_COMPONENTS_SLIDER_H_ */
