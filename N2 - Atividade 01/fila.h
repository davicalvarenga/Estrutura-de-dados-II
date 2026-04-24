#ifndef FILA_H
#define FILA_H

#include <stdlib.h>

typedef struct Queuenode {
    void* dado;
    struct Queuenode* proximo;
} Queuenode;

typedef struct Queue {
    Queuenode* inicio;
    Queuenode* fim;
} Queue;

void  initQueue(Queue* fila);
int   isEmptyQueue(Queue* fila);
void  Enqueue(Queue* fila, void* dado);
void* Dequeue(Queue* fila);
void  destroyQueue(Queue* fila);

#endif