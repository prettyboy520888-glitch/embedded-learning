#include <REGX52.H>

void Delay(unsigned int xms) //@12.000MHz
{
    unsigned char i, j;
    while(xms--)
    {
        i = 2;
        j = 239;
        do
        {
            while (--j);
        } while (--i);
    }
}

unsigned char Reverse8(unsigned char x)
{
    unsigned char y = 0;
    unsigned char i;
    for(i=0;i<8;i++)
    {
        y <<= 1;
        y |= (x & 0x01);
        x >>= 1;
    }
    return y;
}

void main()
{
    unsigned char LEDNum = 0;   // 1) ??????(????)

    P2 = Reverse8(LEDNum);     // 2) ???????(?????)

    while(1)
    {
        if(P3_1==0)
        {
            Delay(20);
            while(P3_1==0);
            Delay(20);

            LEDNum++;           // 3) ??????+1
            P2 = ~Reverse8(LEDNum);
        }
    }
}
