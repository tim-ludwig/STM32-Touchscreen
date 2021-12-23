/*
 * Container.cpp
 *
 *  Created on: 21 Dec 2021
 *      Author: TIm Ludwig
 */

#include <touchlib/components/Container.h>

namespace touchlib {
	Container::Container() :
			Component() {

	}

	Container::Container(int _x, int _y, int _width, int _height) :
			Component(_x, _y, _width, _height) {

	}

	void Container::addComponent(Component* c) {
		box.resizeToFit(c->getBoundingBox());

		components.push_back(c);
	}

	void Container::removeComponent(Component* c) {
		components.remove(c);
	}

	void Container::onEvent(TouchEvent& event) {
		for (Component* c : components) {
			if (!c->getBoundingBox().contains(event.getX(), event.getY()))
				continue;

			enteredOn.push_back(c);
			c->onEvent(event);
		}
	}

	void Container::onEvent(DragEvent& event) {
		if (enteredOn.empty()) {
			for (Component* c : components) {
				if (!c->getBoundingBox().contains(event.getX(), event.getY()))
					continue;

				c->onEvent(event);
			}
		} else {
			for (Component* c : enteredOn) {
				c->onEvent(event);
			}
		}
	}

	void Container::onEvent(ReleaseEvent& event) {
		if (enteredOn.empty()) {
			for (Component* c : components) {
				if (!c->getBoundingBox().contains(event.getX(), event.getY()))
					continue;

				c->onEvent(event);
			}
		} else {
			for (Component* c : enteredOn) {
				c->onEvent(event);
			}
			enteredOn.clear();
		}
	}

	void Container::show(cDevDisplayGraphic& lcd) {
		for (Component* c : components) {
			c->show(lcd);
		}
	}
}
