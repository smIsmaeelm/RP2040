/**
  ******************************************************************************
  * @file           : example.c
  * @brief          : Main program body
  ******************************************************************************
  *
  * COPYRIGHT(c) 2022 Faradars
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of Faradars nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
  
/* Includes ------------------------------------------------------------------*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "hardware/gpio.h"
#include "../lib/sim800l.h"

/* USER CODE BEGIN Includes */

/* variables ---------------------------------------------------------*/
#define USER_LED_PIN 25

/* variables ---------------------------------------------------------*/


/* function prototypes -----------------------------------------------*/
void GPIO_Conf_(void);
void UART_Conf(void);
void Task1(void);

/* function prototypes -----------------------------------------------*/

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  *
  * @retval None
  */
  
 int main() {

	 /* MCU Configuration----------------------------------------------------------*/	
    stdio_init_all();
    GPIO_Conf_();
    printf("configuring pins...\n");
    UART_Conf();
    printf("UART is initialized!\n");

	/* Infinit While--------------------------------------------------------------*/
  
		while(1) {
        //Read SMS
        //Check SMS
        //Delete SMS
        //do the task
        //CallNumber

        char DATA[]= readSMS();
        while(DATA[]!="OFF");
        delallSMS();
        callNumber();
        Task1();
        printf("I'll call you soon!\n");
        if(getCallStatus()!=1) {
          callNumber();
        }
    }

  }
  
/**
  * @brief  Setting GPIOS
  *
  * @retval None
  */
 void GPIO_Conf_(void) {
      gpio_init(USER_LED_PIN);
      gpio_set_dir(USER_LED_PIN,true);
      gpio_set_function(TX_PIN,GPIO_FUNC_UART); //tx
      gpio_set_function(RX_PIN,GPIO_FUNC_UART); //rx
  } 

/**
  * @brief  UART Initializing
  *
  * @retval None
  */
 void UART_Conf(void) {
       uart_init(SIM800_UART,115200);
       uart_is_enabled(SIM800_UART);
  } 

  /**
  * @brief  Turn on LED
  *
  * @retval None
  */
  void Task(void) {
    gpio_put(USER_LED_PIN, true);
  }
 	 /* End Code----------------------------------------------------------*/	
