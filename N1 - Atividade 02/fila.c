#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

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

void* Dequeue(Queue* fila) {
    if(isEmptyQueue(fila)) {
        return NULL;
    }
    void* dado = fila->inicio->dado;
    Queuenode* temp = fila->inicio;
    fila->inicio = fila->inicio->proximo;
    free(temp);
    if (isEmptyQueue(fila)) {
        fila->fim = NULL;
    }
    return dado;
}

void destroyQueue(Queue* fila) {
    while (!isEmptyQueue(fila)) {
        Dequeue(fila);
    }
}