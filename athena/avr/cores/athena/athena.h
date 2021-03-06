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


#ifndef ATHENA_H
#define ATHENA_H

/*Inclusoes dos modulos*/

#include "defines.h"

#include "inputs.h"
#include "outputs.h"
#include "timer.h"
#include "counter.h"
#include "pulse.h"

/*Configuracoes iniciais*/
class Athena {
public:
	Athena() {
        /*Economia de energia*/
		ACSR |= (1<<ACD);/*desativa comparadores analogicos*/
		PRR = 255;/*desativa perifericos*/
	}
};

/*Habilita configuracoes iniciais*/
static Athena athena;

/*Prototipo Entradas e Saidas pre definidas, instancias feitas no arquivo main.cpp*/

#ifdef ATHENA328P

extern Entrada I0;
extern Entrada I1;
extern Entrada I2;
extern Entrada I3;
extern Entrada I4;
extern Entrada I5;

extern Saida Q0;
extern Saida Q1;
extern Saida Q2;
extern Saida Q3;
extern Saida Q4;
extern Saida Q5;

#endif

#ifdef ATHENA328

extern Entrada I0;
extern Entrada I1;
extern Entrada I2;
extern Entrada I3;

extern Saida Q0;
extern Saida Q1;
extern Saida Q2;
extern Saida Q3;

#endif

#ifdef ATHENA85

extern Entrada I0;
extern Entrada I1;

extern Saida Q0;
extern Saida Q1;
extern Saida Q2;

#endif

#endif
