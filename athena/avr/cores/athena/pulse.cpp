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


#include "pulse.h"

logico Pulsador::leitura() {
	return _estado;
}

void Pulsador::verifica(logico io) {
	if( io && _trava == 0 ) {
		_estado = !_estado;
		_trava = 1;
	}
	if( !io )
		_trava = 0;
}

Pulsador::Pulsador() {
	_estado = 0;
}

void Pulsador::operator= (logico v) {
	verifica(v);
}

logico Pulsador::operator& (logico v) {
	return leitura()&v;
}

logico Pulsador::operator| (logico v) {
	return leitura()|v;
}

logico Pulsador::operator! () {
	return !leitura();
}
