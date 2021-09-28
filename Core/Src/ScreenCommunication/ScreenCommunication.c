/*
 * ScreenCommunication.c
 *
 *  Created on: 2021年7月28日
 *      Author: fan
 */

#include "ScreenCommunication.h"
#include "stm32f1xx_ll_usart.h"
#include "SimpleProtocolPraise.h"

USART_TypeDef *Screenport=USART3;
uint8_t FunctionA=0,FunctionB=0;

void Screen_Init(USART_TypeDef *USARTx)
{
	Screenport=USARTx;
}

void Screen_Recive(uint8_t date)
{
	uint8_t buffer[32]={ '\0' };
	uint8_t len=0;
	GeneratePraiseWithSuffixMethod(date, "\r\n", 2, buffer, 32, len, Screen_Recivematch(buffer, len - 2));
}

void Screen_Recivematch(uint8_t *date,uint8_t len)
{
	uint8_t valid_data=0;
	if(*date==0x41)
	{
		for(uint8_t i=0;i<len;i++)
		{
			valid_data=*(date+i);
			switch(valid_data)
			{
			case 0x31: FunctionA=1;
			break;
			case 0x32: FunctionA=2;
			break;
			case 0x33: FunctionA=3;
			break;
			}
		}
	}else if(*date==0x42){
		for(uint8_t i=0;i<len;i++)
		{
			valid_data=*(date+i);
			switch(valid_data)
			{
			case 0x31: FunctionB=1;
			break;
			case 0x32: FunctionB=2;
			break;
			case 0x33: FunctionB=3;
			break;
			}
		}
	}
}
