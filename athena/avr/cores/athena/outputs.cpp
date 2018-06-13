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

void Saida::configura(opcao pino, sfr registradores) {
	
	_pino = pino;
	_registrador = registradores+port;

	*((sfr)registradores+port) &= ~bv(pino);
	*((sfr)registradores+ddr) |= bv(pino);
}

void Saida::atualiza(logico v) {
	_estado = v;
	if(v)
		*_registrador |= bv(_pino);
	else
		*_registrador &= ~bv(_pino);
}

logico Saida::leitura() {
	return _estado;
}

Saida::Saida() {
}

Saida::Saida(opcao pino, sfr registradores){ 
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
