/*
 * bluetooth.h
 *
 *  Created on: 2021年7月28日
 *      Author: fan
 */

#ifndef SRC_BLUETOOTH_BLUETOOTH_H_
#define SRC_BLUETOOTH_BLUETOOTH_H_

#include "stm32f1xx_ll_usart.h"

void BlueTooth_Init(USART_TypeDef *USARTx);

void BlueTooth_Recive(uint8_t bluedate);

void BlueTooth_Sendflag(uint8_t flag);

void BlueTooth_Senddate(float Bluedate[],uint8_t len);

void Blue_Recivematch(uint8_t *date,uint8_t len);

#endif /* SRC_BLUETOOTH_BLUETOOTH_H_ */
