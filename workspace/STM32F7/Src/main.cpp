//*******************************************************************
/*!
 \file   main.cpp
 \author Thomas Breuer
 \date   18.09.2019
 \brief  Template
 */

//*******************************************************************
#include <stdio.h>

#include "lib.h"
#include "config.h"

#include "Game.h"
#include "TouchScreen.h"

//*******************************************************************

static WORD min(WORD a, WORD b) {
		return a < b ? a : b;
}

int main(void) {
	lcd.clear();
	TouchScreen touch(cHwI2Cmaster::Device(i2c, 0x54 /*I2C-Addresse*/));
	touch.refresh();

	WORD sideLength = min(lcd.getWidth(), lcd.getHeight());
	WORD cellSize = sideLength / 3;
	WORD left = sideLength < lcd.getWidth() ? (lcd.getWidth() - sideLength) / 2 : 0;
	WORD top = sideLength < lcd.getHeight() ? (lcd.getHeight() - sideLength) / 2 : 0;

	Game g;
	g.draw(lcd);

	while(!g.hasEnded()){
		do {
			touch.refresh();
			//lcd.printf(0, 0, 10, "waiting...");
			//lcd.refresh();
		} while(touch.getTouchCount() == 0);

		WORD x = (touch.getX0() - left) / cellSize;
		WORD y = ((lcd.getHeight() - touch.getY0()) - top) / cellSize;

		g.doMove(Move(x, y));
		g.draw(lcd);

		g.doMove(g.bestMove());
		g.draw(lcd);
	}

	char winner = g.winner();
	if(winner == ' ') lcd.printf(0, 0, 5, "Draw!");
	else lcd.printf(0, 0, 6, "%c won!", winner);

	lcd.refresh();
}
