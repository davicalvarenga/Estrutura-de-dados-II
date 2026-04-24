#ifndef PILHA_H
#define PILHA_H

#include <stdlib.h>

typedef struct StackNode {
    void* dado;
    struct StackNode* proximo;
} StackNode;

typedef struct Stack {
    StackNode* topo;
    int tamanho;
} Stack;

void initStack(Stack* stack);
int isEmptyStack(Stack* stack);
void Push(Stack* stack, void* dado);
void* Pop(Stack* stack);
void destroyStack(Stack* stack);

#endif