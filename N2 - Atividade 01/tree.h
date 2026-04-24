#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include "fila.h"

typedef struct node {
    int valor;
    struct node* esquerda;
    struct node* direita;
} node; 

int  isEmpty(node* raiz);
void insertTree(node** raiz, int valor);
void initTree(node** raiz);
void destroyTree(node** raiz);
void bfs(node* raiz);
node* getMin(node* raiz);
node* getMax(node* raiz);
void  printItem(node* raiz, int valor);
void inOrder(node* raiz);
void preOrder(node* raiz);
void postOrder(node* raiz);
void preOrderInterativo(node* raiz);
void inOrderInterativo(node* raiz);
void postOrderInterativo(node* raiz);
void printTreeVisual(node* raiz);


#endif
