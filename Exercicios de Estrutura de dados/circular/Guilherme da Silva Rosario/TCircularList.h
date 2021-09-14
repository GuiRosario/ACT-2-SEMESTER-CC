#ifndef TCIRCULAR_LIST_H
#define TCIRCULAR_LIST_H

typedef struct circular_list TCircularList;

TCircularList* TCircularList_create();
int TCircularList_insert_begin(TCircularList*, int);
int TCircularList_insert_end(TCircularList*, int);
int EDMUNDO(int,int);
void TCircularList_print(TCircularList*);

#endif 