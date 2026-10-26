#include "LPC214x.h"

void DACInit(void);
void delay(void);

int main(void)
{
    unsigned int i = 0;
    unsigned int sinevalues[32] = {
         512,  612,  708,  796,  873,  937,  984, 1013,
        1023, 1013,  984,  937,  873,  796,  708,  612,
         512,  412,  316,  228,  151,   87,   40,   11,
           1,   11,   40,   87,  151,  228,  316,  412
    };

    DACInit();

    while (1)
    {
        while (i <= 31)
        {
            DACR = (sinevalues[i] << 6);
            delay();
            i++;
        }
        i = 0;
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
    for (count = 0; count < 1000; count++)
    {}
}
