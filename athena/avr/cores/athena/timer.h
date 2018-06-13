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


#ifndef _TIMER_H_
#define _TIMER_H_

#include "defines.h"

class Temporizador {
	
protected:
	
	numerico _tempo;
	longo _referencia;
	
	logico _estado;
	logico _trava;
	
private:

	virtual void configura(numerico);
	void verifica(logico);
	logico leitura();

public:

	Temporizador();
	Temporizador(numerico);
	
	void operator= (logico);
	logico operator& (logico);
	logico operator| (logico);
	logico operator! ();

};

#endif
