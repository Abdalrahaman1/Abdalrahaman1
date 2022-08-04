#include "low_layer.h"



/*This function is used to initialize the list*/
void            Creat_List          (List* Ptl)
{
    Ptl -> top = NULL;
    Ptl -> alpha_order = NULL;
    Ptl -> list_size = 0;
}

/*This function is used to add new student_node to the end of list*/
void            Insert_Node         (List* Ptl, Student_Info* data)
{
    Student_Node* Ptn = (Student_Node*)malloc(sizeof(Student_Node));

    /*copy all student information into the new node*/
    Ptn -> student = *data;

    /*insertion of first node*/
    if(!(Ptl -> list_size))
    {
        Ptn -> next = Ptn;
        Ptn -> previous = Ptn;
        Ptl -> alpha_order = Ptn;
    }
    else                                                    /*insertion new node as last node*/
    {
        Ptn -> next = Ptl -> top -> next;
        Ptn -> previous = Ptl -> top;
        Ptl -> top -> next -> previous = Ptn;
        Ptl -> top -> next = Ptn;
    }
    Ptl -> top = Ptn;
    Ptl -> list_size++;
}

/*This function is used to delete a student_node in the list*/
void            Delete_Node         (List* Ptl, unsigned short id1)
{
    uint8 i = 0;
    sint8 confirmation = '\0';
    Student_Node* Ptn = Ptl -> alpha_order;

    /*search in list for node with the same id1*/
    for(i = 0; ((!(Ptn -> student.id == id1)) && (i < (Ptl -> list_size)));i++)
    {
        Ptn = Ptn -> next;
    }

    /*check if i found the id or not\
    if i was less than list_size that means we found it*/
    if(i < Ptl -> list_size)
    {

        printf("Student%hu name: %s\n", i + 1, Ptn -> student.name);
        printf("Student%hu Phone number: %s\n", i + 1, Ptn -> student.phone);
        printf("Student%hu Address: %s\n", i + 1, Ptn -> student.address);
        printf("Student%hu ID: %hu\n", i + 1, Ptn -> student.id);
        printf("Student%hu Birthday: %s\n", i + 1, Ptn -> student.birthday);
        printf("Student%hu CS grade: %f\n", i + 1, Ptn -> student.cs_grade);
        printf("\n");

        /*check for confirmation to delete the founded node\
        loops while entered character is neither y nor n*/
        do
        {
            printf("Are you sure you want to delete student %hu (Hint: Enter y for yes, n for no)\n\
            your confirmation: ", Ptn ->student.id);
            scanf(" %c", &confirmation);
        }while(confirmation != 'y' && confirmation != 'n');

        /*if user confirmed, then i shall delete that node*/
        if(confirmation == 'y')
        {
            Ptn -> next -> previous = Ptn -> previous;
            Ptn -> previous -> next = Ptn -> next;

            /*check if node i want to delete is the last node or not*/
            if(Ptl -> top == Ptn)                                   /*last node*/
            {
                if(Ptl -> list_size == 1)                           /*only one node in list*/
                {
                    Ptl -> top = NULL;
                }
                else                                                /*more than one node*/
                {
                    Ptl -> top = Ptl -> top -> previous;
                }

            }
            else
            {}

            /*check if node i want to delete is the first node or not*/
            if(Ptl -> alpha_order == Ptn)                           /*first node*/
            {
                if(Ptl -> list_size == 1)                           /*only one node in list*/
                {
                    Ptl -> alpha_order = NULL;
                }
                else                                                /*more than one node*/
                {
                    Ptl -> alpha_order = Ptl -> alpha_order -> next;
                }

            }
            else
            {}

            Ptl -> list_size--;

            free(Ptn);
        }
        else                                                        /*it shall not be deleted*/
        {}

    system("cls");
    }
    else
    {
        system("cls");
        printf("Couldn't find student id: %hu\n", id1);
        printf("\n");
    }
}

/*This function is used to check id heap is full but due to large heap size of computer\
we always return false*/
unsigned char   List_Full           (List* Ptl)
{
    return 0;
}

/*This function is used to check if list is empty or not,\
returns 1 if empty and  0 if not*/
unsigned char   List_Empty          (List* Ptl)
{
    return !(Ptl -> list_size);
}

/*This function is used to clear all student_nodes from heap*/
void            clear_List          (List* Ptl)
{
    Student_Node* Ptn = Ptl -> top;

    while(Ptl -> list_size)
    {
        Ptn = Ptl -> top;
        Ptl -> top = Ptl -> top -> previous;
        free(Ptn);
        Ptl -> list_size--;
    }
    Ptl -> top = NULL;
    Ptl -> alpha_order = NULL;
}

