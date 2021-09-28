/*
 * ScreenCommunication.h
 *
 *  Created on: 2021年7月28日
 *      Author: fan
 */

#ifndef SRC_SCREENCOMMUNICATION_SCREENCOMMUNICATION_H_
#define SRC_SCREENCOMMUNICATION_SCREENCOMMUNICATION_H_

#include "stm32f1xx_ll_usart.h"

void Screen_Init(USART_TypeDef *USARTx);

void Screen_Recive(uint8_t date);

void Screen_Recivematch(uint8_t *date,uint8_t len);

#endif /* SRC_SCREENCOMMUNICATION_SCREENCOMMUNICATION_H_ */
