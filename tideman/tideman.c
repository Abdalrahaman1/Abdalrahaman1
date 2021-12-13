#include "tideman.h"


unsigned short pair_count = 0;

char* candidate[candidates] = {"alice","bob","charlie"};
unsigned short ranks[candidates];
unsigned short preferences[candidates][candidates] = {0};
pair pairs[3];
boolean locked[candidates][candidates] = {false};


void tideman (void)
{
    unsigned short votes = 0, i = 0, j = 0;
    do
    {
        printf("Number of votes: ");
        scanf("%hu",&votes);
    }while(votes < 1);

    while(i < votes)
    {
        j = 0;
        while(j < candidates)
        {
            char *p2s = (char*)malloc(sizeof(char) * 9);
            printf("Rank %hu: ",j+1);
            scanf(" %[^\n]s",p2s);
            vote(j++, p2s, ranks);
            free(p2s);
        }
        printf("\n");
        record_preferences(ranks);
        i++;
    }
    add_pairs();
    sort_pairs();
    lock_pairs();
    print_pairs();
}


boolean vote (unsigned short rank, char* str, unsigned short *ranks)
{
    unsigned short i = 0;
    boolean status = false;
    for(i = 0; i < candidates; i++)
    {
        if(!stringcompare(candidate[i],str))
        {
            ranks[rank] = i;
            status = true;
            break;
        }
        else
        {}
    }
    return status;
}

void record_preferences (unsigned short *ranks)
{
    unsigned short row = 0, colomn = 0;
    for(row = 0; row < candidates-1; row++)
    {
        for(colomn = row+1; colomn < candidates; colomn++)
        {
                preferences[ranks[row]][ranks[colomn]] += 1;
        }
    }
}

void add_pairs (void)
{
    unsigned short row = 0, colomn = 0;
    for(row = 0; row < candidates ;row++)
    {
        for(colomn = row+1; colomn < candidates; colomn++)
        {
            if(preferences[row][colomn] > preferences[colomn][row])
            {
                pairs[pair_count].winner = row;
                pairs[pair_count++].loser = colomn;
            }
            else if(preferences[row][colomn] < preferences[colomn][row])
            {
                pairs[pair_count].winner = colomn;
                pairs[pair_count++].loser = row;
            }
            else
            {}
        }
    }
}

void sort_pairs (void)
{
    merge(pairs, pair_count);
}

void lock_pairs (void)
{
    unsigned short i = 0;
    boolean status = true;
    while(i < pair_count)
    {
        status = true;
        if(i > 1)
        {
            status = pair_check(pairs[i].winner,pairs[i].loser , i-1, status);
        }
        locked[pairs[i].winner][pairs[i].loser] = status;
        i++;
    }
}

void print_pairs (void)
{
    unsigned short i = 0, j = 0, k = 0;
    while(i < candidates)
    {
        if(k == candidates)
        {
            break;
        }
        else
        {
            k = 0, j = 0;
            while(j < candidates)
            {
                if(locked[j++][i] == false)
                {
                    k++;
                }
                else
                {}
            }
        }
        i++;
    }
    printf("winner is: %s", candidate[--i]);
}

boolean stringcompare (char* str1, char* str2)
{
    unsigned short i = 0;
    boolean status = true;
    if(size(str1) == size(str2))
    {
        while(str1[i] != '\0')
        {
            if(str1[i] == str2[i])
            {
                status = false;
            }
            else
            {
                status = true;
                break;
            }
            i++;
        }
    }
    return status;
}

boolean pair_check (unsigned short winner, unsigned short loser, unsigned short y, boolean z)
{
    signed short k = y;
    while(k >= 0)
    {
        if(z)
        {
            if(loser == pairs[k].winner)
            {
                if(winner == pairs[k].loser)
                {
                    z = false;
                }
                else
                {
                    pair_check(winner, pairs[k].loser, y, z);
                }
            }
            else
            {
                k--;
            }
        }
        else
        {
            break;
        }
    }

    return z;
}

void merge (pair *p2arr, unsigned short maxx)
{
    if((maxx/2) > 0)
    {
        unsigned short i = 0, j = 0, k = 0;
        pair larr[maxx/2], rarr[maxx - (maxx/2)];
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
                if((i < (maxx/2)) && ((preferences[larr[i].winner] - preferences[larr[i].loser]) > (preferences[rarr[j].winner] - preferences[rarr[j].loser])))
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

unsigned short size (char* str)
{
    unsigned short i = 0;
    for(i = 0; str[i] != '\0'; ++i)
    {}
    return i;
}

unsigned short sum (unsigned short i)
{
    unsigned short sum = 0;
    for(i -= 1; i > 0; i--)
    {
        sum += i;
    }
    return sum;
}
