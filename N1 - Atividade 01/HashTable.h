#ifndef HashTable_H
#define HashTable_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include "node.h"

#define TABLE_SIZE 3

typedef struct HashTable{
    Node *table[TABLE_SIZE];
} HashTable;

void setAluno(Aluno* a, long int mat, const char* nome) {
    a->matricula = mat;
    strcpy(a->nome, nome);
}

int hashFunction(long int mat) {
    return mat % TABLE_SIZE;
}

void initHashTable(HashTable* ht) {
    for( int i = 0; i < TABLE_SIZE; i++) {
      ht->table[i] = NULL;
    }
}

void insertItem(HashTable *ht, Aluno* aluno){
    int index = hashFunction(aluno->matricula);
    Node *newNode=(Node *)malloc(sizeof(Node));

    newNode->value= aluno;
    newNode->next = ht->table[index];
    ht->table[index]=newNode;
}

void deleteItem(HashTable* ht, Aluno* aluno) {
    int index = hashFunction(aluno->matricula);
    Node *current= ht->table[index];
    Node *anterior = NULL;
    while (current != NULL)
    {
        if(current->value->matricula == aluno->matricula) {
            
            if(anterior == NULL) {
                ht->table[index] = current->next;
            }
            else {
                anterior->next = current->next;
            }

            free(current);
            break;
    }
        else {
            anterior = current;
            current = current->next;
        }
    }
}

void displayHashTable(HashTable *ht)
{
    printf("\n--- Estado Atual da Tabela Hash ---\n");
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        printf("Indice [%d]: ", i);
        Node *current = ht->table[i];
        
        if (current == NULL) {
            printf("NULL");
        }

        while(current != NULL)
        {
            printf("-> [Mat: %ld | %s] ", current->value->matricula, current->value->nome);
            current = current->next;            
        }
        printf("\n");
    }
    printf("-----------------------------------\n");
}

void freeHashTable(HashTable *ht)
{
    for(int i=0;i<TABLE_SIZE;i++)
    {
        Node *current=ht->table[i];
        while(current!=NULL)
        {   
            Node *temp=current;
            current=current->next;
            free(temp);            
        }
        ht->table[i]=NULL;
    }
   
    
}

#endif // HashTable_H