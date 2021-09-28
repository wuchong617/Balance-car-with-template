/*
 * TOF.c
 *
 *  Created on: 2021年7月29日
 *      Author: fan
 */
#include "TOF.h"
#include <stdint.h>
#include <string.h>

uint16_t distance=0;

void Get_TOF_distance(uint8_t date)
{
	uint8_t TOF_date[32]={0},i=0;
	TOF_date[i]=date;
	i++;
	if(i==9&&TOF_date[0]==0x59)
	{
		if(TOF_date[1]==0x59)
		{
			distance=(TOF_date[3]<<8)|TOF_date[2];
			i=0;
			memset(TOF_date,0,32);
		}else{
			i=0;
			memset(TOF_date,0,32);
		}
	}else{
		i=0;
		memset(TOF_date,0,32);
	}
}
