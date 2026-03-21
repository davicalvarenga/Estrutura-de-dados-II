#ifndef NODE_H
#define NODE_H

#include "Aluno.h"

typedef struct Node {
    Aluno* value;
    struct Node *next;
} Node;

#endif 