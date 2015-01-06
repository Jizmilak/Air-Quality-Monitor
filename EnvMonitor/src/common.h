/*-------------------------------------------------------------------
  common.h

  Released under the MIT License  - see
  http://www.opensource.org/licenses/mit-license.php
-------------------------------------------------------------------*/

#ifndef _COMMON_H_
#define _COMMON_H_ 1

#define BOOL    char

#define FALSE   0
#define TRUE    (!FALSE)
//#define NULL    0

#define nop() do { __asm__ __volatile__ ("nop"); } while (0)

// The following macros set/clear bits

#define set_bit(port,bit)  (port |= (1<<bit))
#define clear_bit(port,bit)  (port &= ~(1<<bit))
#define test_bit( reg, bitNumb )   ((reg) & (1 << (bitNumb)))

#if 0
#define INIT_CTR0	256 - 187			// timer/counter 0 starting point
#define INIT_CTR1	65536 - 4688		// timer/counter 1 starting point

#define RX_BUF_SIZE  32
#define TX_BUF_SIZE  16

#define EVENT_RX_FRAME_COMPLETE	0		// event flags bits
#define EVENT_RX_FRAME_ERROR	1
#define EVENT_INTERVAL_EXPIRED	2
#define EVENT_BUTTON1_RELEASED	3
#define EVENT_BUTTON2_RELEASED	4
#define EVENT_SYSTEM_TIMEOUT	5

#define ONE_MIN_OF_100MS		600
#endif

#endif

