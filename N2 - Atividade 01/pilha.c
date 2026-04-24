#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

void initStack(Stack* stack) {
    stack->topo = NULL;
    stack->tamanho = 0;
}

int isEmptyStack(Stack* stack) {
    return stack->topo == NULL;
}

void Push(Stack* stack, void* dado) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->dado = dado;
    newNode->proximo = stack->topo;
    stack->topo = newNode;
    stack->tamanho++;
}

void* Pop(Stack* stack) {
    if(isEmptyStack(stack)) {
        return NULL;
    }
    StackNode* temp = stack->topo;
    void* dado = temp->dado;
    stack->topo = temp->proximo;
    free(temp);
    stack->tamanho--;
    return dado;
}

void destroyStack(Stack* stack) {
    while (!isEmptyStack(stack)) {
        Pop(stack);
    }
}