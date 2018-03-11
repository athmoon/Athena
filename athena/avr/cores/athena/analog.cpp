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


#include "analog.h"


Analog::Analog() {
	PRR &= ~bv(PRADC);
}

uint16_t Analog::read(uint8_t pin) {
	if (pin != 0 || pin != 1)
		return 0;
	ADMUX &= ~(bv(MUX3)|bv(MUX2)|bv(MUX1)|bv(MUX0));
	ADMUX |= pin;
    ADCSRA = bv(ADEN)|bv(ADSC)|6;
    while(ADCSRA & bv(ADSC));
    uint16_t _adc = ADC;
    return _adc;
}
