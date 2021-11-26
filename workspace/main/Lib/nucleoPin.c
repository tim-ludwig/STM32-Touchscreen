/*
 * nucleoPort.c
 *
 *  Created on: 22 Oct 2021
 *      Author: TIm Ludwig
 */

#include "nucleoPin.h"
#include "port.h"

void nucleoPortpinInit(NucleoPin_t pin, unsigned mode, unsigned af) {
	portpinInit(pin.ptr, pin.pin, mode, af);
}

void nucleoPortpinSet(NucleoPin_t pin, unsigned value) {
	portpinSet(pin.ptr, pin.pin, value);
}

unsigned nucleoPortpinGet(NucleoPin_t pin) {
	return portpinGet(pin.ptr, pin.pin);
}
