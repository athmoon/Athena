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


#include "defines.h"
#include "inputs.h"
#include "outputs.h"

#ifndef ATTINY

Entrada I0(0);
Entrada I1(1);
Entrada I2(2);
Entrada I3(3);

Saida Q0(2);
Saida Q1(3);
Saida Q2(4);
Saida Q3(5);

#else

Entrada I0(3);
Entrada I1(4);

Saida Q0(0);
Saida Q1(1);
Saida Q2(2);

#endif

int main() {
	_delay_ms(1000);
	for(;;) {
		loop();
	}
	return 0;
}
