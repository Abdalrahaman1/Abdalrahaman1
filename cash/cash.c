#include "cash.h"


void cash (void)
{
    float money = 0;

    Check(&money);

    printf("The sum is:%hi",sum_change ((money*100) + 0.5));
}


void Check (float* x)
{
    do
    {
        printf("Enter the money:");
        scanf("%f",x);                             //x is the same as &(*x)
    }while((*x)<0);
}


unsigned short sum_change (signed short money)
{
    return ((money/25) + ((money%25)/10) + (((money%25)%10)/5) + (((money%25)%10)%5));
}
