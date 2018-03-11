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


#include "counter.h"

void Contador::configura(numerico comparar, uint8_t operacao, uint8_t deteccao) {	
	_comparador = comparar;
	_operacao = operacao;
	_deteccao = deteccao;
}

logico Contador::leitura() {
	return _estado;
}

Contador::Contador(numerico comparar, uint8_t operacao, uint8_t deteccao) {
	configura(comparar, operacao, deteccao);
}

void Contador::reset() {
	_estado = 0;
	_contador = 0;
	limpar = 0;
}

void Contador::verifica(logico io) {
	if( io != _anterior ) {
		switch(_deteccao) {
				case subida:
					_contador+= (numerico)io;
					_anterior = io;
					break;
				case descida:
					_contador+= (numerico)!io;
					_anterior = io;
					break;
				case mudanca:
					_contador++;
					_anterior = io;
					break;
		}
	}
	switch(_operacao) {
		case igual:
			_estado = ( _contador == _comparador ? 1 : 0 );
			break;
		case maior:
			_estado = ( _contador > _comparador ? 1 : 0 );
			break;
		case menor:
			_estado = ( _contador < _comparador ? 1 : 0 );
			break;
	}
	if(limpar)
		reset();
}

void Contador::operator= (logico v) {
	verifica(v);
}

logico Contador::operator& (logico v) {
	return leitura()&v;
}

logico Contador::operator| (logico v) {
	return leitura()|v;
}

logico Contador::operator! () {
	return !leitura();
}
