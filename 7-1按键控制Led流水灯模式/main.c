#include <REGX52.H>
#include "KEY.h"
#include "Timer0.h"
#include <INTRINS.H>

unsigned char Keynum,Ledmode;
void main ()
{
	P2=0xFE;
	Timer0_Init();
	while (1)
	{
		Keynum=Key();
		if(Keynum)
		{
			if(Keynum==1)
			{
					Ledmode++;
					if(Ledmode>=2){Ledmode=0;}
			}
			
		}
	}
	
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x18;		
	TH0 = 0xFC;	
	T0Count++;
	if(T0Count>=500)
	{
		T0Count=0;
		if(Ledmode==0)
		{
			P2=_crol_(P2,1);
		}
		if(Ledmode==1)
		{
			P2=_cror_(P2,1);
		}
	}

}