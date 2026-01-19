#include <REGX52.H>
#include <intrins.h>

void Delay500ms()        //@12.000MHz
{
    unsigned char i, j, k;
    _nop_();
    i = 4; j = 205; k = 187;
    do {
        do {
            while (--k);
        } while (--j);
    } while (--i);
}

void main()
{
    unsigned char i;

    P2 = 0xFF;            // ??(???????:1=?)

    while(1)
    {
        for(i = 0; i < 8; i++)   // ????? 7 ??? i<7
        {
            P2 = (unsigned char)~(1 << i);  // ??? i ?
            Delay500ms();

            P2 = 0xFF;          // ??
            Delay500ms();
        }
        Delay500ms();
    }
}
