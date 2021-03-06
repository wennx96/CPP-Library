/*
 * ADC.h
 *
 *  Created on: 2016��7��17��
 *      Author: Wennx-Desktop
 */

#ifndef HEADERS_ADC_H_
#define HEADERS_ADC_H_

#include<IO.h>
#include<LCD.h>
#include<Interrupt.h>


class ADC
{
public:
	static void ADC_Init(int channel = 0)
	{
		//ADC12CTL0 &= ~ADC12ENC;
		ADC12CTL0 = ADC12SHT02 + ADC12MSC + ADC12ON;
		ADC12CTL1 = ADC12SHP+ ADC12CONSEQ_1;
		ADC12IE = 2;
		GPIO::Ports(6).FuncSelect(0, 1);
		GPIO::Ports(7).FuncSelect(0, 1);
		ADC12MCTL0 = ADC12INCH_0;
		ADC12MCTL1 = ADC12INCH_12 + ADC12EOS;
		ADC12CTL0 |= ADC12ENC;
		for(;;)
		{
			ADC12CTL0 |= ADC12SC;

		}
	}
	static void ADCEnable()
	{
		ADC12CTL0 |= ADC12ENC;
	}
	static void ADCStart()
	{

		ADC12CTL0 |= ADC12SC;
	}

};

float sum = 0;
float sum1 = 0;
int count = 0;
int count1 = 0;

#pragma vector=ADC12_VECTOR
__interrupt void ADC_Interrupt()
{
	int i;
	switch(ADC12IV)
	{
	case 6:
		/*sum += ADC12MEM0;
		//tmp /= 819;
		//tmp += 2.5;
		count++;
		if(count == 100)
		{
			//sum /= 1638.0 * count;
			sum /= 1256.1348 * count;
			LCD::WriteNum(sum);
			sum = 0;
			count = 0;
		}
		break;*/
	case 8:
		sum += ADC12MEM0;
		//tmp /= 819;
		//tmp += 2.5;
		count++;
		if(count == 100)
		{
			//sum /= 1638.0 * count;
			sum /= 1256.1348 * count;
			LCD::WriteNum(sum, 1);
			sum = 0;
			count = 0;
		}
		sum1 += ADC12MEM1;
		//tmp /= 819;
		//tmp += 2.5;
		count1++;
		if(count1 == 100)
		{
			//sum /= 1638.0 * count;
			sum1 /= 1256.1348 * count1;
			LCD::WriteNum(sum1, 2);
			sum1 = 0;
			count1 = 0;
		}
	case 10:
	case 12:
	case 14:
	case 16:
	case 18:
	case 20:
	case 22:
	case 24:
	case 26:
	case 28:
	case 30:
		/*sum[0] += ADC12MEM0 / 1253.0599755;
		sum[12] += ADC12MEM12 / 1253.0599755;
		count++;
		if(count == 100)
		{
			LCD::WriteNum(sum[0] / count);
			LCD::WriteNum(sum[12] / count, 2);
			sum[0] = 0;
			sum[12] = 0;
			count = 0;
		}*/
	case 32:
	case 34:
	case 36:


	}
}



#endif /* HEADERS_ADC_H_ */
