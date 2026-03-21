#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 100

typedef struct {
    long int matricula;
    char nome[MAX_NOME];
} Aluno;

#endif // ALUNO_H