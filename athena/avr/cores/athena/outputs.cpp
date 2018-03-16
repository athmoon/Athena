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

void Saida::configura(uint8_t pino, uint8_t registradores) {
	
	_pino = pino;
	_registradores = registradores;
		
	uint8_t* ddr = ++registradores;
	uint8_t* port = ++registradores;

	*port&=~bv(pino);
	*ddr|=bv(pino);
}

void Saida::atualiza(logico v) {
	uint8_t* port = _registradores+2;
	_estado = v;
	if(v)
		*port|=bv(_pino);
	else
		*port&=~bv(_pino);
}

logico Saida::leitura() {
	return _estado;
}

Saida::Saida() {
}

Saida::Saida(uint8_t pino, uint8_t registradores){ 
	configura(pino, registradores);
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
