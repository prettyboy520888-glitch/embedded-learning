#include <REGX52.H>
#include <INTRINS.H>
void Delay1ms(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms)
	{
		xms--;


	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
	}
	
}


void main()
{
	while(1)
	{
		int t = 100;
		P2=0x01;
		Delay1ms(t);
		P2=0x02;
		Delay1ms(t);
		P2=0x04;
		Delay1ms(t);
		P2=0x08;
		Delay1ms(t);
		P2=0x10;
		Delay1ms(t);
		P2=0x20;
		Delay1ms(t);
		P2=0x40;
		Delay1ms(t);
		P2=0x80;
		Delay1ms(t);
	}
}