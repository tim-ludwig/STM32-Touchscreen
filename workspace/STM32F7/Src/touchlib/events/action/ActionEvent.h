/*
 * ActionEvent.h
 *
 *  Created on: 26 Dec 2021
 *      Author: TIm Ludwig
 */

#ifndef TOUCHLIB_EVENTS_ACTION_ACTIONEVENT_H_
#define TOUCHLIB_EVENTS_ACTION_ACTIONEVENT_H_

#include "touchlib/components/Component.h"

namespace touchlib {
	class ActionEvent {
	private:
		Component& target;

	public:
		ActionEvent(Component&);

		Component& getTarget();
	};
}

#endif /* TOUCHLIB_EVENTS_ACTION_ACTIONEVENT_H_ */
