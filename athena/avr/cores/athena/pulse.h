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


#ifndef _PULSE_H_
#define _PULSE_H_

#include "defines.h"

class Pulsador {
	
protected:


	logico _estado;
	logico _trava;
	
private:

	void verifica(logico);
	logico leitura();

public:
	
	Pulsador();
	
	void operator= (logico);
	logico operator& (logico);
	logico operator| (logico);
	logico operator! ();
	
};

#endif

