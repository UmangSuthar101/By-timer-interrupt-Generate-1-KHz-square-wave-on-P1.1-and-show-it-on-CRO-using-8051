#include<reg51.h>		/* Include x51 header file */
sbit test = P1^1;		/* set test pin0 of port1 */

void Timer_init()
{
	TMOD = 0x01;		/* Timer0 mode1 */
	TH0 = 0xFE;		/* 50ms timer value */
	TL0 = 0x34;      
	TR0 = 1;  	      	/* Start timer0 */
}


void Timer0_ISR() interrupt 1	/* Timer0 interrupt service routine (ISR) */
{
	test = ~test;  		/* Toggle port pin */
	TH0 = 0xFE;      	/* 50ms timer value */
	TL0 = 0x34;      
}

int main(void)
{
	EA  = 1;         	/* Enable global interrupt */
	ET0 = 1;         	/* Enable timer0 interrupt */
	Timer_init();
  	while(1);
}