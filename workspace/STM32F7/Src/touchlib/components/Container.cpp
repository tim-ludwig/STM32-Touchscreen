/*
 * Container.cpp
 *
 *  Created on: 21 Dec 2021
 *      Author: TIm Ludwig
 */

#include <touchlib/components/Container.h>
#include "Color.h"

namespace touchlib {
	Container::Container() :
			Component() {

	}

	Container::Container(WORD _x, WORD _y, WORD _width, WORD _height) :
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
			if (!(c->getBoundingBox().contains(event.getX(), event.getY())))
				continue;

			c->onEvent(event);
		}
	}

	void Container::onEvent(DragEvent& event) {
			for (Component* c : components) {
				if (!(c->getBoundingBox().contains(event.getX(), event.getY())))
					continue;

				c->onEvent(event);
			}
	}

	void Container::onEvent(ReleaseEvent& event) {
			for (Component* c : components) {
				if (!(c->getBoundingBox().contains(event.getX(), event.getY())))
					continue;

				c->onEvent(event);
		}
	}

	void Container::show(cDevDisplayGraphic& lcd) {
		lcd.drawRectangle(box.x(), box.y(), box.width(), box.height(), Color::White);
		for (Component* c : components) {
			c->show(lcd);
		}
	}
}
