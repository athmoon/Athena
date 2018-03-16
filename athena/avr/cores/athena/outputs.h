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


#ifndef _SAIDAS_H_
#define _SAIDAS_H_

#include "defines.h"

class Saida {
	
protected:
	
	uint8_t _pino;
	uint8_t _registradores;
	logico _estado;
	
private:
	
	virtual void configura(uint8_t, uint8_t);
	virtual void atualiza(logico);
	logico leitura();

public:

	Saida();
	Saida(uint8_t, uint8_t);
	
	void operator= (logico);
	logico operator& (logico);
	logico operator| (logico);
	logico operator! ();

};

#endif
