/*
    ChibiOS/RT - Copyright (C) 2006,2007,2008,2009,2010,
                 2011 Giovanni Di Sirio.

    This file is part of ChibiOS/RT.

    ChibiOS/RT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS/RT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Setup for the Olimex STM33-P103 proto board.
 */

/*
 * Board identifier.
 */
#define BOARD_DEMO_MODULE
#define BOARD_NAME              "OPERA Demo Module"

/*
 * Board frequencies.
 */
#define STM32_LSECLK            32768
#define STM32_HSECLK            8000000

/*
 * MCU type, supported types are defined in ./os/hal/platforms/hal_lld.h.
 */
#define STM32F10X_MD

/*
 * IO pins assignments.
 */
#define LED_GPIO				GPIOA
#define LED1					0
#define LED2					1
#define LED3					2
#define LED4					3

#define BUTTON_GPIO				GPIOB
#define BUTTON1					1
#define BUTTON2					0

#define GPIOB_SPI2NSS			12

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 *
 * The digits have the following meaning:
 *   0 - Analog input.
 *   1 - Push Pull output 10MHz.
 *   2 - Push Pull output 2MHz.
 *   3 - Push Pull output 50MHz.
 *   4 - Digital input.
 *   5 - Open Drain output 10MHz.
 *   6 - Open Drain output 2MHz.
 *   7 - Open Drain output 50MHz.
 *   8 - Digital input with PullUp or PullDown resistor depending on ODR.
 *   9 - Alternate Push Pull output 10MHz.
 *   A - Alternate Push Pull output 2MHz.
 *   B - Alternate Push Pull output 50MHz.
 *   C - Reserved.
 *   D - Alternate Open Drain output 10MHz.
 *   E - Alternate Open Drain output 2MHz.
 *   F - Alternate Open Drain output 50MHz.
 * Please refer to the STM32 Reference Manual for details.
 */

/*
 * Port A setup.
 * Everything input with pull-up except:
 * PA0  - Push Pull output (LED1).
 * PA1  - Push Pull output (LED2).
 * PA2  - Push Pull output (LED3).
 * PA3  - Push Pull output (LED4).
 * PA4  - Push Pull output (test signal).
 * PA5  - Push Pull output (test signal).
 * PA6  - Push Pull output (test signal).
 * PA7  - Push Pull output (test signal).
 * PA9  - Alternate output (USART2 TX).
 * PA10 - Normal input     (USART2 RX).
 * PA11 - XXX              (USB DM).
 * PA12 - XXX              (USB DP).
*/
#define VAL_GPIOACRL            0x3B333333      /*  PA7...PA0 */
#define VAL_GPIOACRH            0x888884B8      /* PA15...PA8 */
#define VAL_GPIOAODR            0xFFFFFFFF

/*
 * Port B setup.
 * Everything input with pull-up except:
 * PB0  - Normal input (BUTTON2).
 * PB1  - Normal input (BUTTON1).
 * PB6  - Alternate Open Drain output (I2C1 SCL).
 * PB7  - Alternate Open Drain output (I2C1 SDA).
 * PB8  - Normal input (CAN1 RX).
 * PB9  - Alternate output (CAN1 TX).
 * PB12 - Push Pull output (SPI2 CS).
 * PB13 - Alternate output (SPI2 SCK).
 * PB14 - Normal input (SPI2 MISO).
 * PB15 - Alternate output (SPI2 MOSI).
 */
#define VAL_GPIOBCRL            0xFF888888      /*  PB7...PB0 */
#define VAL_GPIOBCRH            0xB4B388B4      /* PB15...PB8 */
#define VAL_GPIOBODR            0xFFFFFFFF

/*
 * Port C setup.
 * Everything input with pull-up except:
 */
#define VAL_GPIOCCRL            0x88888888      /*  PC7...PC0 */
#define VAL_GPIOCCRH            0x88888888      /* PC15...PC8 */
#define VAL_GPIOCODR            0xFFFFFFFF

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */
