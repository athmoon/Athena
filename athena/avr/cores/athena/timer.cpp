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


#include "timer.h"

longo countTime;

ISR(TIMER0_OVF_vect) {
	TCNT0 = 5;
	countTime++;
}

void Temporizador::configura(numerico tempo) {
	PRR &= ~bv(PRTIM0);
	
	_tempo = tempo;
	_estado = 0;
	_trava = 0;
	
	TCCR0A = 0;
	TCCR0B = bv(CS01)|bv(CS00);

#ifndef	ATHENA85
	TIMSK0 = bv(TOIE0);
#else
	TIMSK = bv(TOIE0);
#endif

	sei();
	
}

void Temporizador::verifica(logico v) {
	
	if(v) {
	
		if(!_trava) {
			_referencia = countTime;
			_trava = 1;
		}
	
		if( (countTime - _referencia) >= _tempo ) {
			_estado = 1;
		}
		
	}
	
	else {
		_estado = 0;
		_trava = 0;
	}

}

logico Temporizador::leitura() {
	return _estado;
}

Temporizador::Temporizador() {
}

Temporizador::Temporizador(numerico tempo) {
	configura(tempo);
}

void Temporizador::operator= (logico v) { 
	verifica(v);
}

logico Temporizador::operator& (logico v) {
	return leitura() & v;
}

logico Temporizador::operator| (logico v) {
	return leitura() | v;
}

logico Temporizador::operator! () {
	return !leitura();
}
