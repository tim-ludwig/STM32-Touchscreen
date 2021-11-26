//*******************************************************************
#include <stdio.h>
#include <stdarg.h>
#include "stm32l4xx.h"

//-------------------------------------------------------------------
#include "uart.h"
#include "port.h"

//-------------------------------------------------------------------
#define UART_BUFFER_SIZE  256

//-------------------------------------------------------------------
static char rxBuffer[ UART_BUFFER_SIZE ];
static char txBuffer[ UART_BUFFER_SIZE ];

static unsigned char txReadIdx  = 0;
static unsigned char txWriteIdx = 0;

static unsigned char rxReadIdx  = 0;
static unsigned char rxWriteIdx = 0;

static unsigned char txRunning = 0;

//-------------------------------------------------------------------
void uartInit( void )
{
  RCC->APB1ENR1 |= RCC_APB1ENR1_USART2EN;  // enable USART clock
 // RCC->AHB1ENR  |= AHB1ENR(1 << 0);
  portpinInit( GPIOA, 15, ALTERNATE_FUNC, 3 ); // USART 2 RX
  portpinInit( GPIOA,  2, ALTERNATE_FUNC, 7 ); // USART 2 TX

  NVIC_EnableIRQ( USART2_IRQn );

  USART2->CR2 |=  (0<<12);           // 0: 1 stop bit

  USART2->CR1 |=  (  !USART_CR1_M    // 8 Bit
              | !USART_CR1_PCE       // no parity
              |  USART_CR1_RE        // RX mode
              |  USART_CR1_TE );     // TX mode

  USART2->CR3 |=  (  !USART_CR3_RTSE
              | !USART_CR3_CTSE );   // no hardware flow control

  USART2->BRR  = (unsigned)(72000000L / 19200);

  USART2->CR1 |= (  USART_CR1_UE     // Enable USART
              | USART_CR1_TCIE       // Transm. complete interr. enable
              | USART_CR1_RXNEIE );  // Receive reg. not empty interr. enable
}

//-------------------------------------------------------------------
void uartPrintf( const char *format, ... )
{
  unsigned  i;
  char str[ UART_BUFFER_SIZE+2 ]; // ein paar Zeichen als Reserve

  va_list argzeiger;
  va_start( argzeiger, format );
  vsnprintf( str, UART_BUFFER_SIZE, format, argzeiger );
  va_end( argzeiger);
  
  // Zeichenweise an Display-Speicher uebertragen
  for (i=0; str[i]!=0 && i<UART_BUFFER_SIZE; i++) 
  {    
    txBuffer[txWriteIdx] = str[i];
    txWriteIdx++;

    if( !txRunning ) // Interrupt ausloesen, falls erforderlich
    {
      txRunning = 1;  
      
      USART2->TDR = txBuffer[txReadIdx];
      txReadIdx++;
    }
    while( txReadIdx == (unsigned char)(txWriteIdx+1) ); // warten bis FIFO nicht voll
  }
}

//-------------------------------------------------------------------
char *uartGetString( void )
{
  static char str[ UART_BUFFER_SIZE+2 ]; // ein paar Zeichen als Reserve
  static unsigned pos = 0;
  
  // lese aus FIFO bis String voll, FIFO leer oder '\n' erreicht
  while( rxReadIdx != rxWriteIdx )
  {
    char c = rxBuffer[rxReadIdx];
    rxReadIdx++;
    
    if(c == '\r' || pos >= UART_BUFFER_SIZE-1)
    {
      str[pos] = 0;
      pos = 0;
      return( str );
    }
    else
    {
      str[pos++] = c;
    }
  }
  return( NULL );
}

//-------------------------------------------------------------------
void USART2_IRQHandler( void )
{  
	unsigned char c;
	
  if( USART2->ISR  & USART_ISR_TC ) // transmission complete?
  {
		USART2->ICR |= (USART_ICR_TCCF);
    if( txReadIdx != txWriteIdx ) // FIFO not empty
    {
      USART2->TDR = txBuffer[txReadIdx];
      txReadIdx++;
    }
    else
    {
      txRunning = 0;
			
    }
  }
  
  if( (USART2->ISR  & USART_ISR_RXNE ) || (USART2->ISR & USART_ISR_ORE) ) // receive data register not empty
  {
		c = USART2->RDR;
		
    if( rxReadIdx != (unsigned char)(rxWriteIdx+1) ) // FIFO not full
    {
      rxBuffer[rxWriteIdx] = c;
      rxWriteIdx++;
    }
  }
}
