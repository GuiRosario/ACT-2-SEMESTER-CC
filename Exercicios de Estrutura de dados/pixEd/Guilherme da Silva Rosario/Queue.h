#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue Queue;

Queue* Queue_create();
void Queue_destroy(Queue*);
int Queue_enqueue(Queue*, int,int,float);
int Queue_dequeue(Queue*, int*, int*,float*);
int Queue_head(Queue*, int*,int*,float*);
int Queue_full(Queue*,int);
int Queue_empty(Queue*);
int Queue_qty(Queue*);

#endif