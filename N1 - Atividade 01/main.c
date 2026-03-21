#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"
#include "HashTable.h"

int main() {
    Aluno dados[TABLE_SIZE];
    HashTable ht;
    initHashTable(&ht);
    
    for (int i = 0; i < TABLE_SIZE; i++) {
        char nome[MAX_NOME];
        long int mat;
        printf("Digite o nome %d: ", i);
        scanf("%s", nome);
        printf("Digite a matricula %d: ", i);
        scanf("%ld", &mat);
        setAluno(&dados[i], mat, nome);
    }
    for (int i = 0; i < TABLE_SIZE; i++) {
        insertItem(&ht, &dados[i]);
    }    
    Aluno aluno;
    Aluno aluno2;
    setAluno(&aluno, 2014, "Jose");
    insertItem(&ht, &aluno);
    displayHashTable(&ht);
    deleteItem(&ht, &aluno);
    displayHashTable(&ht);
    setAluno(&aluno2, 2014, "Zeca");
    insertItem(&ht, &aluno2);
    setAluno(&aluno, 2014, "Jose");
    insertItem(&ht, &aluno);
    displayHashTable(&ht);
    deleteItem(&ht, &aluno);
    displayHashTable(&ht);
    freeHashTable(&ht);

    return 0;
}