#ifndef TIDEMAN_H_INCLUDED
#define TIDEMAN_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>


#define candidates 3


typedef enum
{
    false, true
}boolean;

typedef struct
{
    unsigned short winner;
    unsigned short loser;
}pair;


void tideman (void);
boolean vote (unsigned short rank, char* str, unsigned short *ranks);
void record_preferences (unsigned short *ranks);
void add_pairs (void);
void sort_pairs (void);
void lock_pairs (void);
void print_pairs (void);
boolean stringcompare (char* str1, char* str2);
boolean pair_check (unsigned short winner, unsigned short loser, unsigned short y, boolean z);
void merge (pair *p2arr, unsigned short maxx);
unsigned short size (char* str);
unsigned short sum (unsigned short i);


#endif // TIDEMAN_H_INCLUDED
