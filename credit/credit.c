#include "credit.h"


void credit (void)
{
    boolean status = false;
    char credit[18];
    printf("credit number is:");
    scanf("%17s",credit);
    status = check(credit);

    if(status)
    {
        switch(size(credit))
        {
        case 13:
                credit[0] == '4'?printf("Visa\m"):printf("INVALID\n");
                break;
        case 15:
                credit[0] == '3' && (credit[1] == '4' || credit[1] == '7')?printf("American Express"):printf("INVALID\n");
                break;
        case 16:
                switch(credit[0])
                {
                case '4':
                        printf("Visa\n");
                        break;
                case '5':
                        (credit[1] == '1' || credit[1] == '2' || credit[1] == '3' || credit[1] == '4' || credit[1] == '5')?printf("Mastercard\n"):printf("INVALID\n");
                        break;
                default:
                        printf("foo");
                        break;
                }
                break;
        default:
                if(size(credit)>16 || size(credit)<13 || size(credit) == 14)
                {
                    printf("INVALID\n");
                }
                else
                {
                    printf("foo");
                }
                break;
        }
    }
    else if(size(credit)>16 || size(credit)<13 || size(credit) == 14)
    {
        printf("INVALID\n");
    }
    else
    {
        printf("INVALID\n");
    }

}


int size (char* p2s)
{
    unsigned short counter = 0;
    while(p2s[counter] != '\0')
    {
        counter++;
    }
    return (counter);
}

boolean check (char* p2s)
{
    signed short i = (size(p2s)-2), temp = 0, sum = 0;

    while(i>=0)
    {
        temp = ((p2s[i] - 48)*2);
        sum += ((temp/10) + (temp%10));
        i -= 2;
    }

    i = (size(p2s)-1);

    while(i>=0)
    {
        sum += (p2s[i]-48);
        i -= 2;
    }

    return (sum%10)?false:true;
}
