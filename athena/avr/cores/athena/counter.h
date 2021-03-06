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

class Contador {
	
protected:


	logico _anterior;
	logico _estado;	
	
	opcao _deteccao;
	opcao _operacao;
		
	numerico _contador;
	numerico _comparador;
	
private:


	void configura(numerico, opcao, opcao);
	void verifica(logico);
	logico leitura();
	void reset();

public:

	logico limpar;
	
	Contador();	
	Contador(numerico, opcao operacao = igual, opcao deteccao = subida);
	
	void operator= (logico);
	logico operator& (logico);
	logico operator| (logico);
	logico operator! ();
	
};

#endif
