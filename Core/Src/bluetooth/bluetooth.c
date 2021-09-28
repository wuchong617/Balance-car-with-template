/*
 * bluetooth.c
 *
 *  Created on: 2021年7月28日
 *      Author: fan
 */

#include "stm32f1xx_ll_usart.h"
#include "SimpleProtocolPraise.h"

USART_TypeDef *Blueport=USART2;

void BlueTooth_Init(USART_TypeDef *USARTx)
{
	Blueport=USARTx;
}

void BlueTooth_Recive(uint8_t bluedate)
{
	uint8_t buffer[32]={ '\0' };
	uint8_t len=0;
	GeneratePraiseWithSuffixMethod(bluedate, "\r\n", 2, buffer, 32, len, Blue_Recivematch(buffer, len - 2));
}

void Blue_Recivematch(uint8_t *date,uint8_t len)
{
	uint8_t valid_data=0;
	if(*date==0x31)
	{
		for(uint8_t i=0;i<len;i++)
		{
			valid_data=*(date+i);
			switch(valid_data)
			{
			}
		}
	}
}

void BlueTooth_Sendflag(uint8_t flag)
{
	if(flag==1)
	{
		while (LL_USART_IsActiveFlag_TC(Blueport) == RESET);
		LL_USART_TransmitData8(Blueport, 0x31);
	}else{
		while (LL_USART_IsActiveFlag_TC(Blueport) == RESET);
		LL_USART_TransmitData8(Blueport, 0x00);
	}
}

void BlueTooth_Senddate(float Bluedate[],uint8_t len)
{
	uint8_t *hexPtr = (uint8_t*) Bluedate;
	for (uint8_t index = 0; index < len * 4; index++) {
		while (LL_USART_IsActiveFlag_TC(Blueport) == RESET);
		LL_USART_TransmitData8(Blueport, *hexPtr);
		hexPtr++;
	}

	while (LL_USART_IsActiveFlag_TC(Blueport) == RESET);
	LL_USART_TransmitData8(Blueport, 0x80);

	while (LL_USART_IsActiveFlag_TC(Blueport) == RESET);
	LL_USART_TransmitData8(Blueport, 0x7f);
}
