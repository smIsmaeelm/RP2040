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

#include "hardware/uart.h"
#include "../lib/sim800l.h"
#include <string.h>
#include <stdio.h>
/* Variables ------------------------------------------------------------------*/
const uint8_t NUMBER[]= "ATD09224019403;\r\n";
static_assert(sizeof(NUMBER)==18,"[ADD YOUR PHONE NUMBER]: in NUMBER[]"); 
char readbuffer[20];
uint8_t flag=0;
/* Functions ------------------------------------------------------------------*/

/**
  * @brief  Calling the number that is given in NUMBER[]
  *
  * @retval None
  */
  
void callNumber(void) {
	if( uart_is_writable(SIM800_UART)) {
		uart_write_blocking(SIM800_UART,NUMBER,sizeof(NUMBER));
  }  
  readUART1();
}

/**
  * @brief:  	AT command returns OK which implies that the 
  * communication between the device and the application has been verified.
  *
  * @retval:Null
  */
  
void getStatus(void) {

	if( uart_is_writable(SIM800_UART)) {
   uart_write_blocking(SIM800_UART,"AT\r\n",sizeof("AT\r\n"));
  }  
readUART1();
}

 /**
  * @brief  Read UART1 Msgs
  *
  * @retval Flag==0-> Not get OK
  * Flag==1-> Get Ok
  */ 

uint8_t readUART1(void) {
  uint8_t counter=0;
  
      while(uart_is_readable(uart1)) {
        readbuffer[counter]= uart_getc(SIM800_UART);
        printf("%c",readbuffer[counter]);
        if(readbuffer[counter]=='O') {
          flag=1;
        }
        counter++;
      } 
  return flag;
}
