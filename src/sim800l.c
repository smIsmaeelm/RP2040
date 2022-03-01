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
 *        _____________________________
 *       |  RP2040 >>>   SIM800L  |
 *        -----------------------------
 *            GND      >>>   GND
 *        RX  10       >>>   TX    
 *        TX  11       >>>   RX
 *       RESET 2       >>>   RST 
 *                 
 *   POWER SOURCE 4.2V >>> VCC
 */

/* Includes ------------------------------------------------------------------*/

#include "hardware/uart.h"
#include "../lib/sim800l.h"

/* Variables ------------------------------------------------------------------*/
const uint8_t Send_Mesage[]= "ATD09125972430;\r\n";
char readbuffer[100];
/* Functions ------------------------------------------------------------------*/

/**
  * @brief  Calling the number that is given in Send_Mesage[]
  *
  * @retval None
  */
  
void callNumber(void) {
	
	if( uart_is_writable(SIM800_UART)) {
		uart_write_blocking(SIM800_UART,Send_Mesage,sizeof(Send_Mesage));
	}
}

/**
  * @brief  Calling the number that is given in Send_Mesage[]
  *
  * @retval None
  */
  
char readSMS(void) {
	
	if( uart_is_writable(SIM800_UART)) {
    uart_write_blocking(SIM800_UART,"AT+CMGF=1\r",sizeof("AT+CMGF=1\r"));
  }  
    if (uart_is_readable(SIM800_UART)) {
		  uart_read_blocking(SIM800_UART,readbuffer,sizeof(readbuffer));
    }
}

/**
  * @brief  Getting signal quality
  *
  * @retval None
  */
  
void signalquality(void) {
	
	if( uart_is_writable(SIM800_UART)) {
    uart_write_blocking(SIM800_UART,"AT+CSQ\r\n",sizeof("AT+CSQ\r\n"));
  }
    if (uart_is_readable(SIM800_UART)) {
		uart_read_blocking(SIM800_UART,readbuffer,sizeof(readbuffer));
	}
}

/**
  * @brief  Getting signal quality
  *
  * @retval  0 Ready (MT allows commands from TA/TE)
 2 Unknown (MT is not guaranteed to respond to tructions)
 3 Ringing (MT is ready for commands from TA/TE, but the ringer is active)
 4 Call in progress
  */
  
char getCallStatus(void) {

	if( uart_is_writable(SIM800_UART)) {
    uart_write_blocking(SIM800_UART,"AT+CPAS\r\n",sizeof("AT+CPAS\r\n"));
  }  
    if (uart_is_readable(SIM800_UART)) {
		  uart_read_blocking(SIM800_UART,readbuffer,sizeof(readbuffer));
    }
    return 0;
}
  // return _buffer.substring(_buffer.indexOf("+CPAS: ")+7,_buffer.indexOf("+CPAS: ")+9).toInt();

/**
  * @brief  Getting signal quality
  *
  * @retval None
  */
  
// void readSms(uint8_t index){
//   SIM.print (F("AT+CMGF=1\r")); 
//   if (( _readSerial().indexOf("ER")) ==-1) {
//     SIM.print (F("AT+CMGR="));
//     SIM.print (index);
//     SIM.print("\r");
//     _buffer=_readSerial();
//     if (_buffer.indexOf("CMGR:")!=-1){
//       return _buffer;
//     }
//     else return "";    
//     }
//   else
//     return "";
// }

/**
  * @brief  Getting signal quality
  *
  * @retval None
  */
  
uint8_t delallSMS(void) {
  	if (uart_is_writable(SIM800_UART)) {
    uart_write_blocking(SIM800_UART,"at+cmgda=\"del all\"\n\r",sizeof("at+cmgda=\"del all\"\n\r"));
    }
    if (uart_is_readable(SIM800_UART)) {
		  uart_read_blocking(SIM800_UART,readbuffer,sizeof(readbuffer));
    }
    return 0;
}
      
//
//void delAllSms(){ 
//   SIM.print(F("at+cmgda=\"del all\"\n\r"));
//   _buffer=_readSerial();
//   if (_buffer.indexOf("OK")!=-1) {return true;}else {return false;}
  
// }