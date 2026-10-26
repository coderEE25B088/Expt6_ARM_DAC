#include "LPC214x.h"
 
void DACInit(void);
void delay(void);
 
int main(void)
{
    unsigned int squarevalues[2] = {0, 775};
 
    DACInit();
 
    while (1)
    {
        DACR = (squarevalues[0] << 6);
        delay();
        DACR = (squarevalues[1] << 6);
        delay();
    }
}
 
void DACInit(void)
{
    PINSEL1 &= ~(3 << 18);
    PINSEL1 |= (2 << 18);
}
 
void delay(void)
{
    volatile unsigned int count;
    for (count = 0; count < 16000; count++)
    {}
}
