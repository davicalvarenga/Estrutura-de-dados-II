#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include "fila.h"

typedef struct node {
    int valor;
    struct node* esquerda;
    struct node* direita;
} node; 

int   isEmpty(node* raiz);
void  initTree(node** raiz);
void  destroyTree(node** raiz);

node* insert(node** raiz, int valor);
node* search(node* raiz, int valor);

void  bfs(node* raiz);

#endif
