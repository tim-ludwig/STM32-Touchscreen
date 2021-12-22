//*******************************************************************
/*!
 \file   main.cpp
 \author Thomas Breuer, Tim Ludwig
 \date   18.09.2019
 \brief  Template
 */

//*******************************************************************
#include "lib.h"
#include "config.h"
#include <tictactoe/TicTacToe.h>
#include "touchlib/TouchScreen.h"
#include "touchlib/components/Container.h"
#include "touchlib/components/TicTacToeGame.h"
#include "touchlib/components/Slider.h"
#include "Color.h"

//*******************************************************************

using touchlib::TicTacToeGame;
using touchlib::Slider;
using touchlib::Container;

void tictactoe(void) {
	Container root{0, 0, lcd.getWidth(), lcd.getHeight()};
	lcd.clear();
	Game game;
	TicTacToeGame g(game, true, lcd.getWidth(), lcd.getHeight());

	root.addComponent(&g);
	touchScreen.setRootContainer(&root);

	com.printf("\r\nNeues Spiel!\r\n");

	while (!game.hasEnded()) {
		if (game.getCurrentPlayer() == 'o')
			game.doMove(game.bestMove());

		game.uartPrint(com);

		lcd.clear();
		g.show(lcd);
		lcd.refresh();
	}

	char winner = game.winner();
	if (winner == ' ') {
		lcd.printf(1, 1, 5, "Draw!");
		com.printf("Draw!\r\n");
	} else {
		lcd.printf(1, 1, 6, "%c won!", winner);
		com.printf("%c won!\r\n", winner);
	}

	lcd.refresh();

	root.removeComponent(&g);
}

int main(void) {
	Container root{0, 0, lcd.getWidth(), lcd.getHeight()};

	Slider s{100, 100, 300, 50, true, 15, 0.0};
	root.addComponent(&s);
	touchScreen.setRootContainer(&root);

	while(true) {
		lcd.drawRectangle(0, 0, lcd.getWidth(), lcd.getHeight(), Color::White);
		s.show(lcd);
		lcd.printf(1, 1, 5, "%d", (int)(100*s.getPosition()));
		lcd.refresh();
	}

	root.removeComponent(&s);
}

