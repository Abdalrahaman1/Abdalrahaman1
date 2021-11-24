#include "mario.h"


signed short hight = 0;


void mario (void)
{
    Check(&hight);

    Design(hight);
}


void Check (signed short* x)
{
    do
    {
        printf("Hight:");
        scanf("%hi",x);
    }while((*x)<min || (*x)>max);
}


void Print_hashtage (unsigned char j)
{
    while(j)
        {
            printf("#");
            j--;
        }
}


void Print_space (unsigned char j)
{
    while(hight - j)
        {
            printf(" ");
            j++;
        }
}


void Design (signed short x)
{
    unsigned char i;
    for(i=min ; i<=x ; i++)
    {

        Print_space(i);

        Print_hashtage(i);

        printf("  ");

        Print_hashtage(i);

        printf("\n");
    }
}
