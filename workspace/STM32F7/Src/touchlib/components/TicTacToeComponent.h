/*
 * TicTacToeGame.h
 *
 *  Created on: 17 Dec 2021
 *      Author: TIm Ludwig
 */

#ifndef TOUCHLIB_COMPONENTS_TICTACTOECOMPONENT_H_
#define TOUCHLIB_COMPONENTS_TICTACTOECOMPONENT_H_

#include "tictactoe/TicTacToe.h"
#include "touchlib/components/Component.h"
#include "lib.h"

namespace touchlib {
	class TicTacToeComponent : public Component {
	private:
		TicTacToeGame& g;
		WORD sideLength, cellSize;
		bool ai;

	public:
		TicTacToeComponent(TicTacToeGame&, bool ai, int w, int h);

		virtual void onEvent(TouchEvent&);
		virtual void onEvent(DragEvent&);
		virtual void onEvent(ReleaseEvent&);

		void show(cDevDisplayGraphic&);
	};
}

#endif /* TOUCHLIB_COMPONENTS_TICTACTOECOMPONENT_H_ */
