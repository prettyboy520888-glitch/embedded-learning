#include <REGX52.H>
#include "MatrixKey.h"
#include "LCD1602.h"
#include "DELAY.h"

void main()
{
			int key=0;

			unsigned char Count = 0;
			char number;
			LCD_Init();
			LCD_ShowString(1, 1, "Password:");
			LCD_ShowNum(2,1,key,4);
			
		
			while(1)
			{
				number = MatrixKey();
					if(number) 
        {
							if(number<=10) 
							{
									if(Count < 4) 
								{
										if(number==10){number=0;}
										key = key * 10;      
										key = key + number;  
										
									 
										Count++; 
										
										
										LCD_ShowNum(2, 1, key, 4); 
								}
							}
							if(number==12) 
							{
								key=0;
							  LCD_ShowString(1, 1, "Password:");
							  LCD_ShowNum(2, 1, 0000, 4); 
							}
				}
						if(Count == 4)
            {
                if(key == 1234)
                {
                    LCD_ShowString(2, 1, "Yes  "); 
										while(1){}
                }
                else
                {
                    LCD_ShowString(2, 1, "Error"); 
                    Delay(1000); 
                    key = 0;
                    Count = 0;
                    LCD_ShowString(1, 1, "Password:"); 
                    LCD_ShowNum(2, 1, key, 4);  
										LCD_Init();
										LCD_ShowString(1, 1, "Password:");
									  LCD_ShowNum(2, 1, 0000, 4); 
                }			
						}
			}
}
