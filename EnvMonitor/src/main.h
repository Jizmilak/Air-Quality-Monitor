/*-----------------------------------------------------------------
  All code is provided for EDUCATIONAL purposes ONLY. There is no
  warranty and no support.

  nokia_clock by Jack Botner

  main.h
-----------------------------------------------------------------*/
#ifndef _MAIN_H_
#define _MAIN_H_

#include "common.h"

#define INIT_CTR0			( 256 - 125 )

#define MAX_CHECKS       	6		// number of tests before a switch is debounced

// Events bits
#define EVENT_UPDATE_LCD		0
#define EVENT_CLOCK_TICK		1
#define EVENT_POWER_UP			2
#define EVENT_UPDATE_EEPROM		3
#define EVENT_BUTTON_PRESSED	4
#define EVENT_ENCODER_CW		5
#define EVENT_ENCODER_CCW		6
#define EVENT_POWER_DOWN		7

// Debounced switches bits
#define ENC_SWITCH_A			0
#define ENC_SWITCH_B			1
#define ENC_SWITCH_PB			2

// Rotary encoder port defines
#define ENCODER_PORT			PINC
#define ENCODER_A				PC0
#define ENCODER_B				PC1
#define ENCODER_PB				PC2

// Other ports
#define VCC_GOOD_PORT			PIND
#define VCC_GOOD_PIN			PD6

#define FORMAT_12HRS			0
#define FORMAT_24HRS			1

// Functions

void program_clock(void);


#endif  //_MAIN_H_
