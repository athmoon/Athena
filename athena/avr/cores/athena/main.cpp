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

#ifdef ATHENA328P

Entrada I0(2, &PIND);
Entrada I1(3, &PIND);
Entrada I2(4, &PIND);
Entrada I3(5, &PIND);
Entrada I4(6, &PIND);
Entrada I5(7, &PIND);

Saida Q0(0, &PINB);
Saida Q1(1, &PINB);
Saida Q2(2, &PINB);
Saida Q3(3, &PINB);
Saida Q4(4, &PINB);
Saida Q5(5, &PINB);

#endif

#ifdef ATHENA328

Entrada I0(2, &PIND);
Entrada I1(3, &PIND);
Entrada I2(4, &PIND);
Entrada I3(5, &PIND);

Saida Q0(0, &PINB);
Saida Q1(1, &PINB);
Saida Q2(2, &PINB);
Saida Q3(3, &PINB);

#endif

#ifdef ATHENA85

Entrada I0(3, &PINB);
Entrada I1(4, &PINB);

Saida Q0(0, &PINB);
Saida Q1(1, &PINB);
Saida Q2(2, &PINB);

#endif

int main() {
	_delay_ms(1000);
	for(;;) {
		loop();
	}
	return 0;
}
