#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>


#define msizeof(type) (char*)(&type+1)-(char*)(&type)


void bubble_sort (void);
void rand_filling (unsigned short *arr);
void selection_sort (void);
void insertion_sort (void);
void merge_sort (void);
void merge (unsigned short *p2arr, unsigned short maxx);
void String_Concatenation (char* str1, char* str2);
unsigned short size (char* str);


typedef enum
{
    false,true
}boolean;


#endif // SORT_H_INCLUDED
