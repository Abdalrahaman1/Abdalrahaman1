#ifndef HIGH_LAYER_H_INCLUDED
#define HIGH_LAYER_H_INCLUDED


#include "low_layer.h"


/*Extern global variables to be accessible by all files that include low_layer*/
extern void    (*Ptfunctions[6])   (void);
extern List l;


/*functions prototype*/
void    New_Student         (void);
void    Delete_Student      (void);
void    Student_List        (void);
void    Student_Edit        (void);
void    Rank_student        (void);
void    Student_score       (void);


#endif // HIGH_LAYER_H_INCLUDED
