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


#ifndef _COUNTER_H_
#define _COUNTER_H_

#include "defines.h"

#define subida 	((uint8_t)100)
#define descida	((uint8_t)101)
#define mudanca	((uint8_t)102)

#define igual	((uint8_t)103)
#define maior	((uint8_t)104)
#define menor	((uint8_t)105)

class Contador {
	
protected:


	logico _anterior;
	logico _estado;	
	
	uint8_t _deteccao;
	uint8_t _operacao;
		
	numerico _contador;
	numerico _comparador;
	
private:


	void configura(numerico, uint8_t, uint8_t);
	void verifica(logico);
	logico leitura();
	void reset();

public:

	logico limpar;
	
	Contador();	
	Contador(numerico, uint8_t operacao = igual, uint8_t deteccao = subida);
	
	void operator= (logico);
	logico operator& (logico);
	logico operator| (logico);
	logico operator! ();
	
};

#endif
