#include "high_layer.h"


/*Definition of l of type list structure*/
List l;


/*Definition of polymorphism which is an array of pointers to all functions\
used in this program*/
void    (*Ptfunctions[6])   (void) = {New_Student, Delete_Student, Student_List, Student_Edit, Rank_student, Student_score};


/*This function is used to add a new student_node to list l and\
storing all student information inside that node*/
void    New_Student         (void)
{
    system("cls");
    /*check if list is full*/
    if(!List_Full(&l))
    {                                                                               /*list not full*/
        /*store all new student information in temp student*/
        Student_Info temp_student;
        printf("Student name: ");
        scanf(" %[^\n]s", temp_student.name);
        printf("Student Phone number: ");
        scanf(" %[^\n]s", temp_student.phone);
        printf("Student Address: ");
        scanf(" %[^\n]s", temp_student.address);
        printf("Student ID: ");
        scanf("%hu", &temp_student.id);
        printf("Student Birthday: ");
        scanf(" %[^\n]s", temp_student.birthday);
        printf("Student CS grade: ");
        scanf("%f", &temp_student.cs_grade);
        printf("\n");
        Insert_Node(&l, &temp_student);                                             /*add new node*/
    }
    else                                                                            /*list is full*/
    {}
    system("cls");
}

/*This function is used if list is not empty to delete a student_node by asking for name of student_node\
and searching for that name in the list. if that name is found then that node would\
be deleted if not, then i would print that that name is not found, else would print list is empty*/
void    Delete_Student      (void)
{
    system("cls");

    /*check if list is empty*/
    if(!List_Empty(&l))                                             /*list is not empty*/
    {
        unsigned short id1 = 0;
        printf("Enter Student name you want to delete: ");
        scanf("%hu", &id1);
        Delete_Node(&l, id1);
    }
    else                                                            /*list is empty*/
    {
        printf("Students list is empty.\n");
        printf("\n");
    }

}

/*This function is used  if list is not empty to print all students informations\
in students name alphabetical order, else would print list is empty*/
void    Student_List        (void)
{
    system("cls");

    /*if list is empty do nothing*/
    if(!List_Empty(&l))
    {                                                                                   /*list is not empty*/
        uint16 i = 0, j = 0;
        /*creating temp student information structure*/
        Student_Info temp_student;

        Student_Node* Ptn1 = l.alpha_order;
        Student_Node* Ptn2 = Ptn1-> next;

        /*using bubbly sort to sort list in alphabetical ascending order*/
        for(i = 0; i < l.list_size - 1; i++)
        {
            Ptn2 = Ptn1 -> next;
            for(j = i + 1; j < l.list_size; j++)
            {
                if(strcmp(Ptn2 -> student.name, Ptn1 -> student.name) < 0)          /*swap if name in ptn2 is less than name in ptn1*/
                {
                    temp_student = Ptn2 ->student;
                    Ptn2 -> student = Ptn1 -> student;
                    Ptn1 -> student = temp_student;
                }
                else
                {}

                Ptn2 = Ptn2 -> next;
            }
            Ptn1 = Ptn1 -> next;
        }

        Ptn1 = l.alpha_order;

        /*prints all list nodes informations*/
        for(i = 0; i < l.list_size; i++)
        {
            printf("Student%hu name: %s\n", i + 1, Ptn1 -> student.name);
            printf("Student%hu Phone number: %s\n", i + 1, Ptn1 -> student.phone);
            printf("Student%hu Address: %s\n", i + 1, Ptn1 -> student.address);
            printf("Student%hu ID: %hu\n", i + 1, Ptn1 -> student.id);
            printf("Student%hu Birthday: %s\n", i + 1, Ptn1 -> student.birthday);
            printf("Student%hu CS grade: %f\n", i + 1, Ptn1 -> student.cs_grade);
            printf("\n");
            Ptn1  = Ptn1 -> next;
        }
    }
    else                                                                                /*list is empty*/
    {
        printf("Students list is empty.\n");
        printf("\n");
    }
}

/*This function is used if list is not empty to edit a student information\
by asking for student name wanted to be edited, else would print list is empty*/
void    Student_Edit        (void)
{
    system("cls");

    /*if list is empty do nothing*/
    if(List_Empty(&l))                                      /*list is empty*/
    {
        printf("Students list is empty.\n");
        printf("\n");
    }
    else                                                    /*list is not empty*/
    {

        sint8 choice  = '1', i = 0;
        uint16 id1;
        Student_Node* Ptn = l.alpha_order;

        /*scan from user the id of node he want to edit its information*/
        printf("Enter the id of Student you want to edit:");
        scanf("%hu", &id1);

        /*search in list for node with the same id1*/
        for(i = 0; ((!(Ptn -> student.id == id1)) && (i < (l.list_size))); i++)
            {
                Ptn = Ptn -> next;
            }

        /*if i < list_size, then we found it*/
        if(i < l.list_size)
        {
            /*loop for all student information or user enter 7 for exit*/
            for(i = 0; i < 6 && choice != '7'; i++)
            {

                printf("Which data you want to edit.(hint: Enter number of the operation you wanna make)\n\
                        1- Student name.\n\
                        2- Student address.\n\
                        3- Student phone number.\n\
                        4- Student birthday.\n\
                        5- Student id.\n\
                        6- Student cs grade.\n\
                        7- exit.\n\
                your choice is: ");

                scanf(" %c", &choice);

                switch(choice)
                {
                    case '1':
                        printf("Student new name: ");
                        scanf(" %[^\n]s", Ptn -> student.name);
                        break;

                    case '2':
                        printf("Student Address: ");
                        scanf(" %[^\n]s", Ptn -> student.address);
                        break;

                    case '3':
                        printf("Student new Phone number: ");
                        scanf(" %[^\n]s", Ptn -> student.phone);
                        break;

                    case '4':
                        printf("Student new Birthday: ");
                        scanf(" %[^\n]s", Ptn -> student.birthday);
                        break;

                    case '5':
                        printf("Student nwe ID: ");
                        scanf(" %hu", &Ptn -> student.id);
                        break;

                    case '6':
                        printf("Student new CS grade: ");
                        scanf(" %f", &Ptn -> student.cs_grade);
                        break;

                    case '7':
                        break;

                    default:
                        printf("Please enter number from 1 to 7");
                    break;
                }
            }
        }
        else                                                            /*didn't find it*/
        {
            printf("Couldn't find student id: %hu", id1);
        }

        system("cls");

        /*print edited node*/
        printf("Student%hu name: %s\n", i + 1, Ptn -> student.name);
        printf("Student%hu Phone number: %s\n", i + 1, Ptn -> student.phone);
        printf("Student%hu Address: %s\n", i + 1, Ptn -> student.address);
        printf("Student%hu ID: %hu\n", i + 1, Ptn -> student.id);
        printf("Student%hu Birthday: %s\n", i + 1, Ptn -> student.birthday);
        printf("Student%hu CS grade: %f\n", i + 1, Ptn -> student.cs_grade);
        printf("\n");
    }
}

/*This function is used if list is not empty to sort all students information\
to descending order of CS score, else would print list is empty*/
void    Rank_student        (void)
{
    system("cls");

    /*if list is empty do nothing*/
    if(!List_Empty(&l))
    {                                                                           /*list is not empty*/
         uint16 i = 0, j = 0;

        /*creating temp student information structure*/
        Student_Info temp_student;

        Student_Node* Ptn1 = l.alpha_order;
        Student_Node* Ptn2 = Ptn1-> next;

        /*using bubbly sort to sort list in sc score descending order*/
        for(i = 0; i < l.list_size - 1; i++)
        {
            Ptn2 = Ptn1 -> next;
            for(j = i + 1; j < l.list_size; j++)
            {
                if(Ptn2 ->student.cs_grade > Ptn1 ->student.cs_grade)          /*swap if sc score in ptn2 is less than sc score in ptn1*/
                {
                    temp_student = Ptn2 ->student;
                    Ptn2 -> student = Ptn1 -> student;
                    Ptn1 -> student = temp_student;
                }
                else
                {}

                Ptn2 = Ptn2 -> next;
            }
            Ptn1 = Ptn1 -> next;
        }

        Ptn1 = l.alpha_order;

        /*print sorted list in descending sc score order*/
        for(i = l.list_size; i; i--)
        {
            printf("CS Score of Student %s = %f\n", Ptn1 ->student.name, Ptn1 ->student.cs_grade);
            Ptn1 = Ptn1 -> next;
        }

    }
    else                                                                    /*list is empty*/
    {
        printf("Students list is empty.\n");
    }

    printf("\n");
}


/*This function is used id list is not empty to scan all students new cs score and then print them all again*/
void    Student_score       (void)
{
    system("cls");

     /*if list is empty do nothing*/
    if(List_Empty(&l))                                                          /*list is empty*/
    {
        printf("Students list is empty.\n");
        printf("\n");
    }
    else                                                                        /*list is not empty*/
    {
        uint16 i = 0;
        Student_Node* Ptn = l.alpha_order;

        /*loop for all list nodes to scan new cs scores*/
        for(i = l.list_size; i; i--)
        {
            printf("New CS Score of Student %s: ", Ptn ->student.name);
            scanf("%f", &Ptn ->student.cs_grade);
            Ptn = Ptn -> next;
        }

        system("cls");

        Ptn = l.alpha_order;

        /*loop for all list nodes to print new cs scores*/
        for(i = l.list_size; i; i--)
        {
            printf("New CS Score of Student %s = %f\n", Ptn ->student.name, Ptn ->student.cs_grade);
            Ptn = Ptn -> next;
        }
        printf("\n");
    }
}
