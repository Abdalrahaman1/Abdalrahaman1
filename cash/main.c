#include <stdio.h>
#include <stdlib.h>

#define sum_change(x) ((x/25) + ((x%25)/10) + (((x%25)%10)/5) + (((x%25)%10)%5))

void Check (signed short *x);

int main(void)
{
    signed short money = 0;

    Check(&money);

    printf("The sum is:%hi",sum_change(money));

    return 0;
}

void Check (signed short* x)
{
    do
    {
        printf("Enter the money:");
        scanf("%hi",x);                             //x is the same as &(*x)
    }while((*x)<0);
}
