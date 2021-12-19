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
#include "touchlib/components/TicTacToeGame.h"


//*******************************************************************

int main(void) {
	lcd.clear();
	cHwI2Cmaster::Device i2cTouch(i2c, 0x54 /*I2C-Addresse*/);
	TouchScreen touch(800, 472, i2cTouch, cHwPort_N::PortId::PI, (BYTE) 13);
	touch.setInterruptMode(true);

	Game game;
	TicTacToeGame g(touch, lcd, game);
	com.printf("\r\nNeues Spiel!\r\n");

	while(!game.hasEnded()){
		if(game.getCurrentPlayer() == 'o') game.doMove(game.bestMove());
		//com.printf("%d\r\n", touch.getTouchCount());
		lcd.clear();
		g.show();
		game.uartPrint(com);
		lcd.refresh();
	}

	char winner = game.winner();
	if(winner == ' ') {
		lcd.printf(0, 0, 5, "Draw!");
		com.printf("Draw!\r\n");
	} else {
		lcd.printf(0, 0, 6, "%c won!", winner);
		com.printf("%c won!\r\n", winner);
	}

	lcd.refresh();
}

