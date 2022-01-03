/*
 * Container.h
 *
 *  Created on: 21 Dec 2021
 *      Author: TIm Ludwig
 */

#ifndef TOUCHLIB_COMPONENTS_CONTAINER_H_
#define TOUCHLIB_COMPONENTS_CONTAINER_H_

#include <touchlib/components/Component.h>
#include <list>

namespace touchlib {
	class Container : public Component {
	private:
		std::list<Component*> components, enteredOn;

	public:
		Container();
		Container(WORD x, WORD y, WORD w, WORD h);

		void addComponent(Component*);
		void removeComponent(Component*);

		void onEvent(DragEvent&);
		void onEvent(TouchEvent&);
		void onEvent(ReleaseEvent&);

		void show(cDevDisplayGraphic&);
	};
}
#endif /* TOUCHLIB_COMPONENTS_CONTAINER_H_ */
