#include "application.h"


/*This function is called only once in main and used to initialize the global list l*/
void    Setup               (void)
{
    Creat_List(&l);
}

/*this function is used repeatedly in while loop in main to to execute the selected operation*/
void    Main_Menu           (void)
{
    sint8 choice = '\0';

/*this loop accept only numbers from 1:6*/
    do
    {

        printf("Hello, how can i help you.(hint: Enter number of the operation you wanna make)\n\
                1- Add New Student.\n\
                2- Delete Student.\n\
                3- Student List.\n\
                4- Student Edit.\n\
                5- Rank Students.\n\
                6- Student Score.\n\
        your choice is: ");

        scanf(" %c", &choice);

        system("cls");

        if(!(choice >= '1' && choice <= '6'))
        {
            printf("Please enter number from 1 to 6");
        }
        else
        {}

        printf("\n");

    }while(!(choice >= '1' && choice <= '6'));

/*calling the desired function according to chosen number*/
    Ptfunctions[choice - '1']();
}
