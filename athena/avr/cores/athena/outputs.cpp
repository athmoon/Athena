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


#include "outputs.h"

void Saida::configura(uint8_t pin) {
	_pin = pin;
	estado = 0;
#ifndef ATTINY
	PORTD&=~bv(_pin);
	DDRD|=bv(_pin);
#else
	PORTB&=~bv(_pin);
	DDRB|=bv(_pin);
#endif
}

void Saida::atualiza(logico v) {
	estado = v;
	if(v)
#ifndef ATTINY
		PORTD|=bv(_pin);
#else
		PORTB|=bv(_pin);
#endif
	else
#ifndef ATTINY
		PORTB&=~bv(_pin);
#else
		PORTB&=~bv(_pin);
#endif
}

logico Saida::leitura() {
	return estado;
}

Saida::Saida() {
}

Saida::Saida(uint8_t pin){ 
	configura(pin);
};

void Saida::operator= (logico v) { 
	atualiza(v);
}

logico Saida::operator& (logico v) {
	return leitura() & v;
}

logico Saida::operator| (logico v) {
	return leitura() | v;
}

logico Saida::operator! () {
	return !leitura();
}
