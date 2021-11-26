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

//*******************************************************************

int main(void) {
	lcd.clear();
	cHwI2Cmaster::Device i2cTouch(i2c, 0x54 /*I2C-Addresse*/);

	Game game;

	game.doMove(Move("a1"));

	while(!game.hasEnded()) {
		game.doMove(game.bestMove());
	}
	game.draw(lcd);

}
