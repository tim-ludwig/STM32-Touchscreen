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
#include "Color.h"
#include "lib.h"

class TicTacToeGame : Component {
private:
	Game& g;
	WORD sideLength, cellSize;

public:
	TicTacToeGame(TouchScreen&, cDevDisplayGraphic&, Game&);

	void onTouch();
    void show();
};

#endif /* TOUCHLIB_COMPONENTS_TICTACTOEGAME_H_ */
