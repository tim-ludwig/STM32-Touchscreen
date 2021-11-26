#ifndef NUCLEO_PORT_H
#define NUCLE_PORT_H

#include "stm32l4xx.h"

typedef struct nucleoPin {
	GPIO_TypeDef *ptr;
	unsigned pin;
} NucleoPin_t;

static NucleoPin_t PIN_A0 = { GPIOA, 0 };
static NucleoPin_t PIN_A1 = { GPIOA, 1 };
static NucleoPin_t PIN_A2 = { GPIOA, 3 };
static NucleoPin_t PIN_A3 = { GPIOA, 4 };
static NucleoPin_t PIN_A4 = { GPIOA, 5 };
static NucleoPin_t PIN_A5 = { GPIOA, 6 };
static NucleoPin_t PIN_A6 = { GPIOA, 7 };
static NucleoPin_t PIN_A7 = { GPIOA, 2 };

static NucleoPin_t PIN_D0 = { GPIOA, 10 };
static NucleoPin_t PIN_D1 = { GPIOA, 9 };
static NucleoPin_t PIN_D2 = { GPIOA, 12 };
static NucleoPin_t PIN_D3 = { GPIOB, 0 };
static NucleoPin_t PIN_D4 = { GPIOB, 7 };
static NucleoPin_t PIN_D5 = { GPIOB, 6 };
static NucleoPin_t PIN_D6 = { GPIOB, 1 };
static NucleoPin_t PIN_D7 = { GPIOC, 14 };
static NucleoPin_t PIN_D8 = { GPIOC, 15 };
static NucleoPin_t PIN_D9 = { GPIOA, 8 };
static NucleoPin_t PIN_D10 = { GPIOA, 11 };
static NucleoPin_t PIN_D11 = { GPIOB, 5 };
static NucleoPin_t PIN_D12 = { GPIOB, 4 };
static NucleoPin_t PIN_D13 = { GPIOB, 3 };

static NucleoPin_t LED_LD3 = { GPIOB, 3 };

void nucleoPortpinInit(NucleoPin_t pin, unsigned mode, unsigned af);

void nucleoPortpinSet(NucleoPin_t pin, unsigned value);

unsigned nucleoPortpinGet(NucleoPin_t pin);

#endif
