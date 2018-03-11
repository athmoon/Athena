/*
  Copyright (c) 2018 Marcelo Henrique Moraes

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3.0 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

 */


#include "inputs.h"

void Entrada::configura(uint8_t pin) {
	_pin = pin;
	PORTB|=bv(pin);
	DDRB&=~bv(pin);
}

logico Entrada::leitura() {
	return PINB&bv(_pin) ? 0 : 1; 
}

Entrada::Entrada(uint8_t pin){ 
	configura(pin);
};

logico Entrada::operator& (logico v) {
	return leitura() & v;
}

logico Entrada::operator| (logico v) {
	return leitura() | v;
}

logico Entrada::operator! () {
	return !leitura();
}
