#include "numbermatrix.h"


unsigned short number = 0, i = 1, j = 0, k = 0;
unsigned short arr[17][17] = {0};


void numbermatrix1 (void)
{
    check(&number);

    for(i = 1; i <= number; i++)
    {
        for(j = 0; j < i; j++)
        {
            printf("%hu",number-j);
        }

        for(j; j<number; j++)
        {
            printf("%hu",number-i+1);
        }

        for(j = 0; j<(number-i); j++)
        {
            printf("%hu",number-i+1);
        }

        for(j = i; j > 1; j--)
        {
            printf("%hu",number-j+2);
        }
        printf("\n");
    }

    for(i = number-1; i > 0; i--)
    {
        for(j = 0; j < i; j++)
        {
            printf("%hu",number-j);
        }

        for(j; j<number; j++)
        {
            printf("%hu",number-i+1);
        }

        for(j = 0; j<(number-i); j++)
        {
            printf("%hu",number-i+1);
        }

        for(j = i; j > 1; j--)
        {
            printf("%hu",number-j+2);
        }
        printf("\n");
    }
}


void check (unsigned short* p2n)
{
    do
    {
        printf("Enter the number: ");
        scanf("%hu", p2n);
    }while(*p2n<1 || *p2n>10);
}


void numbermatrix2 (void)
{
    check(&number);

    for(i=0; i<number; i++)
    {
        k = 0;

        for(j=0; j<number; j++)
        {
            if(j<number-i)
            {
                arr[i][number-j-1] = number-i;
                arr[i][number+j-1] = number-i;
            }

            if(k<i)
            {
                arr[i][k] = number-k;
                arr[i][(2*number-2)-k] = number-k;
                k++;
            }
        }
    }

    for(i=0; i<number-1; i++)
    {
        k = 0;

        for(j=0; j<number; j++)
        {
            if(j<i+2)
            {
                arr[i+number][number-j-1] = i+2;
                arr[i+number][number+j-1] = i+2;
            }

            if(k<(number-i-1))
            {
                arr[i+number-1][k] = number-k;
                arr[i+number-1][2*number-2-k] = number-k;
                k++;
            }
        }
    }

    for(i=0; i<2*number-1; i++)
    {
        for(j=0; j<2*number-1; j++)
        {
            printf("%hu",arr[i][j]);
        }
        printf("\n");
    }
}
