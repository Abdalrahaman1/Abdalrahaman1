#ifndef LOW_LAYER_H_INCLUDED
#define LOW_LAYER_H_INCLUDED



#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "stdtypes.h"


/*Definition of students structure which contain all information about a student*/
typedef struct
{
    sint8 name[30];
    float32 cs_grade;
    sint8 address[30];
    uint16 id;
    sint8 phone[12];
    sint8 birthday[11];
}Student_Info;


/*Definition of student_node which contain all information about a student\
and a pointer to next & previous student_node*/
typedef struct student_node
{
    Student_Info student;
    struct student_node* next;
    struct student_node* previous;
}Student_Node;


/*Definition of list structure which contain a pointer to last student_node\
, pointer to first student_node & list_size as number of student_node in that list*/
typedef struct
{
    Student_Node* top;                                  /*pointer to last node if existed*/
    Student_Node* alpha_order;                          /*pointer to first node if existed*/
    uint16 list_size;
}List;


/*functions prototype*/
void            Creat_List          (List* Ptl);
void            Insert_Node         (List* Ptl, Student_Info* data);
void            Delete_Node         (List* Ptl, unsigned short id1);
unsigned char   List_Full           (List* Ptl);
unsigned char   List_Empty          (List* Ptl);
void            clear_List          (List* Ptl);


#endif // LOW_LAYER_H_INCLUDED
