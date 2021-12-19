/*
 * Component.h
 *
 *  Created on: 16 Dec 2021
 *      Author: TIm Ludwig
 */

#ifndef TOUCHLIB_COMPONENTS_COMPONENT_H_
#define TOUCHLIB_COMPONENTS_COMPONENT_H_

#include "touchlib/TouchScreen.h"
#include "touchlib/BoundingBox.h"
#include "lib.h"

namespace touchlib {
	class Component {
	private:
		TouchScreen& touchScreen;

	protected:
		cDevDisplayGraphic& lcd;
		BoundingBox box;

	public:
		Component(TouchScreen&, cDevDisplayGraphic&);
		Component(TouchScreen&, cDevDisplayGraphic&, int, int, int, int);
		~Component();

		BoundingBox& getBoundingBox();

		virtual void onEvent(DragEvent&) = 0;
		virtual void onEvent(TouchEvent&) = 0;
		virtual void onEvent(ReleaseEvent&) = 0;

		virtual void show() = 0;
	};
}

#endif /* TOUCHLIB_COMPONENTS_COMPONENT_H_ */
