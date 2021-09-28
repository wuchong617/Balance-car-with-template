/*
 * L298N.c
 *
 *  Created on: 2021年7月29日
 *      Author: fan
 */
#include "L298N.h"
#include "Clock.h"

L298N_t L298N_IO;
uint8_t A_Go=0,A_Back=0,B_Go=0,B_Back=0;

void L298N_IO_Iint(void)
{
	L298N_IO.MaxPWM_Value=1000;

	L298N_IO.PWMA_Back_Channel=LL_TIM_CHANNEL_CH1;
	L298N_IO.PWMA_Go_Channel=LL_TIM_CHANNEL_CH2;
	L298N_IO.PWMB_Back_Channel=LL_TIM_CHANNEL_CH3;
	L298N_IO.PWMB_Go_Channel=LL_TIM_CHANNEL_CH4;

	L298N_IO.TimPort=TIM4;
}

void L298N_init(L298N_t *L298N)
{
	LL_TIM_CC_EnableChannel(L298N->TimPort,L298N->PWMA_Back_Channel);
	LL_TIM_CC_EnableChannel(L298N->TimPort,L298N->PWMA_Go_Channel);
	LL_TIM_CC_EnableChannel(L298N->TimPort,L298N->PWMB_Back_Channel);
	LL_TIM_CC_EnableChannel(L298N->TimPort,L298N->PWMB_Go_Channel);
}

void Set_A_PWMValue(L298N_t *L298N,int16_t Value)
{
	uint32_t finalvalue=0;
	if(Value>0)
	{
		if(A_Back==1)
		{
			LL_TIM_OC_SetCompareCH1(L298N->TimPort,0);
			LL_TIM_OC_SetCompareCH2(L298N->TimPort,0);
			A_Back=0;
			SleepMillisecond(1);
		}
		if(Value>=L298N->MaxPWM_Value)
		{
			finalvalue=L298N->MaxPWM_Value;
			LL_TIM_OC_SetCompareCH1(L298N->TimPort,0);
			LL_TIM_OC_SetCompareCH2(L298N->TimPort,finalvalue);
		}else{
			finalvalue=Value;
			LL_TIM_OC_SetCompareCH1(L298N->TimPort,0);
			LL_TIM_OC_SetCompareCH2(L298N->TimPort,finalvalue);
		}
		A_Go=1;
	}else if(Value==0){
		LL_TIM_OC_SetCompareCH1(L298N->TimPort,0);
		LL_TIM_OC_SetCompareCH2(L298N->TimPort,0);
	}else{
		if(A_Go==1)
		{
			LL_TIM_OC_SetCompareCH1(L298N->TimPort,0);
			LL_TIM_OC_SetCompareCH2(L298N->TimPort,0);
			A_Go=0;
			SleepMillisecond(1);
		}
		if(Value<= - L298N->MaxPWM_Value)
		{
			finalvalue=L298N->MaxPWM_Value;
			LL_TIM_OC_SetCompareCH1(L298N->TimPort,finalvalue);
			LL_TIM_OC_SetCompareCH2(L298N->TimPort,0);
		}else{
			finalvalue= - Value;
			LL_TIM_OC_SetCompareCH1(L298N_IO.TimPort,finalvalue);
			LL_TIM_OC_SetCompareCH2(L298N_IO.TimPort,0);
		}
		A_Back=1;
	}
}

void Set_B_PWMValue(L298N_t *L298N,int16_t Value)
{
	uint32_t finalvalue=0;
	if(Value>0)
	{
		if(B_Back==1)
		{
			LL_TIM_OC_SetCompareCH3(L298N->TimPort,0);
			LL_TIM_OC_SetCompareCH4(L298N->TimPort,0);
			B_Back=0;
			SleepMillisecond(1);
		}
		if(Value>=L298N->MaxPWM_Value)
		{
			finalvalue=L298N->MaxPWM_Value;
			LL_TIM_OC_SetCompareCH3(L298N->TimPort,0);
			LL_TIM_OC_SetCompareCH4(L298N->TimPort,finalvalue);
		}else{
			finalvalue=Value;
			LL_TIM_OC_SetCompareCH3(L298N->TimPort,0);
			LL_TIM_OC_SetCompareCH4(L298N->TimPort,finalvalue);
		}
		B_Go=1;
	}else if(Value==0){
		LL_TIM_OC_SetCompareCH3(L298N->TimPort,0);
		LL_TIM_OC_SetCompareCH4(L298N->TimPort,0);
	}else{
		if(B_Go==1)
		{
			LL_TIM_OC_SetCompareCH3(L298N->TimPort,0);
			LL_TIM_OC_SetCompareCH4(L298N->TimPort,0);
			B_Go=0;
			SleepMillisecond(1);
		}
		if(Value<= - L298N->MaxPWM_Value)
		{
			finalvalue=L298N->MaxPWM_Value;
			LL_TIM_OC_SetCompareCH3(L298N->TimPort,finalvalue);
			LL_TIM_OC_SetCompareCH4(L298N->TimPort,0);
		}else{
			finalvalue= - Value;
			LL_TIM_OC_SetCompareCH3(L298N->TimPort,finalvalue);
			LL_TIM_OC_SetCompareCH4(L298N->TimPort,0);
		}
		B_Back=1;
	}
}
