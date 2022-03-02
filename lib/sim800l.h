 /*
   ******************************************************************************
  * @file           : sim800l.h
  * @brief          : The library of SIM800l GSM module
  * @date           : 2022
  * @author         : Madani
  * @company        : Faradars
  ******************************************************************************

  *  This program is free software: you can redistribute it and/or modify
  *  it under the terms of the GNU General Public License as published by
  *  the Free Software Foundation, either version 3 of the License, or
  *  (at your option) any later version.

  *  This program is distributed in the hope that it will be useful,
  *  but WITHOUT ANY WARRANTY; without even the implied warranty of
  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  *  GNU General Public License for more details.

  *  You should have received a copy of the GNU General Public License
  *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
  ******************************************************************************
	*/
/*
  PINOUT: 
 *        ___________________________
 *       |  RP2040 >>>   SIM800L  |
 *        ---------------------------
 *        GND        >>>     GND
 *        RX   5     >>>     TX    
 *        TX   4     >>>     RX
 *       RESET 3     >>>     RST 
 *                 
 *   POWER SOURCE 4.2V >>> VCC
 */

/* Includes ------------------------------------------------------------------*/

#ifndef _sim800l_h_
#define _sim800l_h_

/* Defines ------------------------------------------------------------------*/
#define RX_PIN 5
#define TX_PIN 4	
#define SIM800_UART uart1
 
/* Functions ------------------------------------------------------------------*/
uint8_t callNumber(void);
char *readSMS(void);
char *signalquality(void);
void getStatus(void);
uint8_t delallSMS(void);
uint8_t readUART1(void);

#endif
