#include <REGX52.H>
#include "DELAY.H"
#include "LCD1602.H"
#include "MatrixKey.H"

void main()
{
		LCD_Init();
		LCD_ShowString(1,1,"Password:");
		while(1)
		{
				char KeyNum;
				KeyNum=MatrixKey();
				if(KeyNum)
				{
						LCD_ShowNum(2,1,KeyNum,2);
				}
				
		}
}