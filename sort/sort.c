#include "sort.h"

#define max 10


unsigned short arr[max] = {0};



void bubble_sort (void)
{
    rand_filling(arr);
    boolean status = true;
    signed short i = 0, j = 0;

    for(i = 0; i < max; i++)
    {
        printf("%hu, ",arr[i]);
    }

    for(i = 0; i < max-j-1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            arr[i] ^= arr[i+1];
            arr[i+1] ^= arr[i];
            arr[i] ^= arr[i+1];
            status = false;
        }
        else
        {}

        if(i == max-j-2 && !status)
        {
            i = -1;
            j++;
            status = true;
        }
        else
        {}
    }
    for(i = 0; i < max; i++)
    {
        printf("%hu, ", arr[i]);
    }
}

void selection_sort (void)
{
    rand_filling(arr);
    unsigned short i = 0, j = 0;

    for(i = 0; i < max; i++)
    {
        printf("%hu, ",arr[i]);
    }

    for(i = j+1; i < max; i++)
    {
        if(arr[j] > arr[i])
        {
            arr[j] ^= arr[i];
            arr[i] ^= arr[j];
            arr[j] ^= arr[i];
        }
        else
        {}

        if(j < max-1 && i == max-1)
        {
            i = ++j;
        }
    }

    printf("\n");
    for(i = 0; i < max; i++)
    {
        printf("%hu, ",arr[i]);
    }
}

void insertion_sort (void)
{
    rand_filling(arr);
    unsigned short i = 0, j = 0, max_pos = 0, min_pos = 0, temp = 0;

    for(i = 0; i < max; i++)
    {
        printf("%hu, ",arr[i]);
    }

    for(i = 0; i < max; i++)
    {
        j = i+1;
        max_pos = i;
        min_pos = 0;
        while(arr[j] < arr[max_pos])
        {
            min_pos++;
            if(max_pos == 0)
            {
                break;
            }
            else
            {
                max_pos--;
            }
        }

        while(min_pos)
        {
            arr[j] ^= arr[j-1];
            arr[j-1] ^= arr[j];
            arr[j] ^= arr[j-1];
            j--;
            min_pos--;
        }
    }

    printf("\n");
    for(i = 0; i < max; i++)
    {
        printf("%hu, ",arr[i]);
    }

}

void merge_sort (void)
{
    rand_filling(arr);
    unsigned short i = 0;

    for(i = 0; i < max; i++)
    {
        printf("%hu, ",arr[i]);
    }

    merge(arr, max);
    i = 0;
    printf("\n");
    while(i < max)
    {
        printf("%hu, ",arr[i++]);
    }
}

void merge (unsigned short *p2arr, unsigned short maxx)
{
    if((maxx/2) > 0)
    {
        unsigned short i = 0, j = 0, k = 0, larr[maxx/2], rarr[maxx - (maxx/2)];
        for(i = 0; i < maxx-(maxx/2); i++)
        {
            if(i<(maxx/2))
            {
                larr[i] = p2arr[i];
            }
            else
            {}

            rarr[i] = p2arr[(maxx/2) + i];
        }
        merge(larr, maxx/2);
        merge(rarr, maxx - (maxx/2));
        i = 0;
        while(k < maxx)
        {
            if(j < maxx - (maxx/2))
            {
                if(((i) < (maxx/2)) && (larr[i] <= rarr[j]))
                {
                    p2arr[k++] = larr[i++];
                }
                else
                {
                    p2arr[k++] = rarr[j++];
                }
            }
            else
            {
                p2arr[k++] = larr[i++];
            }

        }
    }
    else
    {}
}

void String_Concatenation (char* str1, char* str2)
{
    unsigned short i = 0, str1len = size(str1);
    if(msizeof(str1) >= (size(str1) + size(str2)))
    {
        while(str2[i] != '\0')
        {
            str1[str1len+i] = str2[i++];
        }
    }
}

unsigned short size (char* str)
{
    unsigned short counter = 0;
    while(counter++ != '\0');
    return counter-1;
}

void rand_filling (unsigned short *arr)
{
    unsigned short i = 0;
    for(i = 0; i < max; i++)
    {
        arr[i] = rand()%10;
    }
}
