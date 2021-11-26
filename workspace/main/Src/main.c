#include "../Lib/Sys/stm32l4xx.h"
#include "../Lib/port.h"
#include "../Lib/uart.h"
#include "../Lib/timer.h"
#include "../Lib/nucleoPin.h"

#define BUTTON PIN_D2

unsigned ledState = 0;

void switchLed(void) { nucleoPortpinSet(LED_LD3, ledState=!ledState); }

//--------------------------------------------
int main(void)
{
  char *str;

  nucleoPortpinInit(BUTTON, INPUT|PULL_UP, 0);
  nucleoPortpinInit(PIN_D3, INPUT|PULL_UP, 0);
  nucleoPortpinInit(LED_LD3, OUTPUT, 0);

  timerInit(1000000, switchLed);
  uartInit();

  uartPrintf("TEST\r\n");

  while(0)
  {
    if( nucleoPortpinGet(BUTTON) )
    {
    	nucleoPortpinSet(LED_LD3,1);
    	ledState = 1;
    }
    else
    {
    	nucleoPortpinSet(LED_LD3, 0);
    	ledState = 0;
    }

    if( (str = uartGetString()) != 0 )
    {
      uartPrintf("<%s>\r\n",str);
    }
  }
}
