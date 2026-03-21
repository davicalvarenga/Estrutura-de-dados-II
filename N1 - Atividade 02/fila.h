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

void initQueue(Queue* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

int isEmptyQueue(Queue* fila) {
    return fila->inicio == NULL;
}

void Enqueue(Queue* fila, void* dado) {
    Queuenode* newnode = (Queuenode*)malloc(sizeof(Queuenode));
    newnode->dado = dado;
    newnode->proximo = NULL;
    if (isEmptyQueue(fila)) {
        fila->inicio = newnode;
        fila->fim = newnode;
    } else {
        fila->fim->proximo = newnode;
        fila->fim = newnode;
    }
}

void Dequeue(Queue* fila) {
    if(isEmptyQueue(fila)) {
        return NULL;
    }
    
}


#endif