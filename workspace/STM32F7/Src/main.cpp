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

#include "Color.h"

//*******************************************************************

WORD min(WORD a, WORD b) {
	 return a < b ? a : b;
}

void drawBoard() {
	WORD sideLength = min(lcd.getWidth(), lcd.getHeight());

	WORD cellSize = sideLength/3;
	WORD x = sideLength < lcd.getWidth() ? (lcd.getWidth() - sideLength) / 2 : 0;
	WORD y = sideLength < lcd.getHeight() ? (lcd.getHeight() - sideLength) / 2 : 0;

	lcd.drawRectangle(0, 0, lcd.getWidth(), lcd.getHeight(), Color::White);
	for(int i = 0; i <= 3; i++) {
		lcd.drawLine(x, y + i * cellSize, x + sideLength, y + i * cellSize, 1, Color::Black);
		lcd.drawLine(x + i * cellSize, y, x + i * cellSize, y + sideLength, 1, Color::Black);
	}

	lcd.refresh();
}

int main(void)
{
  lcd.clear();
  //lcd.setZoom(2);

  drawBoard();

  cHwI2Cmaster::Device i2cTouch( i2c, 0x54 /*I2C-Addresse*/ );
    

}
