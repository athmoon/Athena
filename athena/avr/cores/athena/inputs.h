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


#ifndef _ENTRADAS_H_
#define _ENTRADAS_H_

#include "defines.h"

class Entrada {
	
protected:

	opcao _pino;
	sfr _registrador;
	
private:
	
	virtual void 	configura(opcao, sfr);
	virtual logico	leitura();

public:

	Entrada();
	Entrada(opcao, sfr);
	
	logico operator& (logico);
	logico operator| (logico);
	logico operator! ();

};

#endif
