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


#ifndef _DEFINES_H_
#define _DEFINES_H_

#include <avr/io.h>
#include <util/delay.h>
#include <inttypes.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <math.h>
#include "pins_arduino.h"

typedef bool logico;
typedef uint8_t opcao;
typedef uint8_t* sfr;
typedef uint16_t numerico;
typedef uint32_t longo;

#define sbi(_sfr,_bit)		(_sfr|=(1<<_bit))
#define cbi(_sfr,_bit)		(_sfr&=~(1<<_bit))
#define tbi(_sfr,_bit)		(_sfr^=(1<<_bit))

#define is_set(_sfr,_bit)	(_sfr&(1<<_bit))
#define is_clear(_sfr,_bit)	(!(_sfr&(1<<_bit)))

#define bv(_bit)			(1<<_bit)
#define nop() 				asm volatile ("nop")

#define pin		0
#define ddr		1
#define port	2

#define SFR_B		(sfr)&PINB
#define SFR_C		(sfr)&PINC
#define SFR_D		(sfr)&PIND

void loop();

#define programa		void loop()

#define inicio		{
#define fim			}

#define serie		&
#define paralelo	|
#define na			!!
#define nf			!

/*Contador*/
#define subida 	((opcao)100)
#define descida	((opcao)101)
#define mudanca	((opcao)102)
#define igual	((opcao)103)
#define maior	((opcao)104)
#define menor	((opcao)105)

#endif
