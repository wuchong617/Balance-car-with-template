/*
 * L298N.h
 *
 *  Created on: 2021年7月29日
 *      Author: fan
 */

#ifndef SRC_L298N_L298N_H_
#define SRC_L298N_L298N_H_

#include "stm32f1xx_ll_tim.h"
#include "stm32f1xx_ll_gpio.h"

typedef struct
{
		TIM_TypeDef *TimPort;

		uint32_t PWMA_Go_Channel;

		uint32_t PWMA_Back_Channel;

		uint32_t PWMB_Go_Channel;

		uint32_t PWMB_Back_Channel;

		uint16_t MaxPWM_Value;
} L298N_t;

void L298N_IO_Iint(void);
void L298N_init(L298N_t *L298N);
void Set_A_PWMValue(L298N_t *L298N,int16_t Value);
void Set_B_PWMValue(L298N_t *L298N,int16_t Value);

#endif /* SRC_L298N_L298N_H_ */
