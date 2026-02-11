#include <REGX52.H>
#include "LCD1602.h"
void main()
{
	
	LCD_Init();
	LCD_ShowNum(1,1,2,1);
	while(1){}
}