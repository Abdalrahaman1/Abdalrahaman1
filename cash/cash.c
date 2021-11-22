#include "cash.h"


void cash (void)
{
    signed short money = 0;

    Check(&money);

    printf("The sum is:%hi",sum_change (money));
}


void Check (signed short* x)
{
    do
    {
        printf("Enter the money:");
        scanf("%hi",x);                             //x is the same as &(*x)
    }while((*x)<0);
}


unsigned short sum_change (signed short money)
{
    return ((money/25) + ((money%25)/10) + (((money%25)%10)/5) + (((money%25)%10)%5));
}
