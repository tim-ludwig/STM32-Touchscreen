/*
 * TicTacToeGame.h
 *
 *  Created on: 17 Dec 2021
 *      Author: TIm Ludwig
 */

#ifndef TOUCHLIB_COMPONENTS_TICTACTOEGAME_H_
#define TOUCHLIB_COMPONENTS_TICTACTOEGAME_H_

#include "tictactoe/TicTacToe.h"
#include "touchlib/components/Component.h"
#include "lib.h"

namespace touchlib {
	class TicTacToeGame : public Component {
	private:
		Game& g;
		WORD sideLength, cellSize;
		bool ai;

	public:
		TicTacToeGame(Game&, bool, WORD w, WORD h);

		virtual void onEvent(TouchEvent&);
		virtual void onEvent(DragEvent&);
		virtual void onEvent(ReleaseEvent&);

		void show(cDevDisplayGraphic&);
	};
}

#endif /* TOUCHLIB_COMPONENTS_TICTACTOEGAME_H_ */
