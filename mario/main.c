#include <stdio.h>
#include <stdlib.h>

#define max 8
#define min 1

signed short hight = 0;

void Check (signed short* x);
void Print_space (unsigned char j);
void Print_hashtage (unsigned char j);
void Design (signed short x);


int main(void)
{

    Check(&hight);

    Design(hight);

    return 0;
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
    for(i=min ; i<=hight ; i++)
    {

        Print_space(i);

        Print_hashtage(i);

        printf(" ");

        Print_hashtage(i);

        Print_space(i);

        printf("\n");
    }
}
