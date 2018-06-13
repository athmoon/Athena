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

Entrada I0(2, SFR_D);
Entrada I1(3, SFR_D);
Entrada I2(4, SFR_D);
Entrada I3(5, SFR_D);
Entrada I4(6, SFR_D);
Entrada I5(7, SFR_D);

Saida Q0(0, SFR_B);
Saida Q1(1, SFR_B);
Saida Q2(2, SFR_B);
Saida Q3(3, SFR_B);
Saida Q4(4, SFR_B);
Saida Q5(5, SFR_B);

#endif

#ifdef ATHENA328

Entrada I0(2, SFR_D);
Entrada I1(3, SFR_D);
Entrada I2(4, SFR_D);
Entrada I3(5, SFR_D);

Saida Q0(0, SFR_B);
Saida Q1(1, SFR_B);
Saida Q2(2, SFR_B);
Saida Q3(3, SFR_B);

#endif

#ifdef ATHENA85

Entrada I0(3, SFR_B);
Entrada I1(4, SFR_B);

Saida Q0(0, SFR_B);
Saida Q1(1, SFR_B);
Saida Q2(2, SFR_B);

#endif

int main() {
	_delay_ms(1000);
	for(;;) {
		loop();
	}
	return 0;
}
