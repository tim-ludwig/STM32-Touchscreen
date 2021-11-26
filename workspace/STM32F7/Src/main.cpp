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
int main(void)
{
  lcd.clear();
  lcd.printf( 0, 0, 10, "Hello world!" );
  lcd.refresh();
  lcd.drawRectangle(   0, 0, 480, 480, Color::White     );
  lcd.drawRectangle( 480, 0, 320, 480, Color::LightBlue );
	
  lcd.setZoom     ( 2 );
  lcd.setBackColor( Color::Cyan );
  lcd.setTextColor( Color::Black);
 
  lcd.refresh();

  int i = 0;

  cHwI2Cmaster::Device i2cTouch( i2c, 0x54 /*I2C-Addresse*/ );
    
  while(1)
  {
	lcd.drawText( 20, 50, 20, "i:%d",i++ );
    lcd.refresh();
  }
}
