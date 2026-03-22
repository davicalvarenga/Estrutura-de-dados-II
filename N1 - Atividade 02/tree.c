#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"
#include "fila.h"

void initTree(node** raiz) {
    *raiz = NULL;
}

void insertTree(node** raiz, int valor) {
    if (*raiz == NULL) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->valor = valor;
    newnode->esquerda = NULL;
    newnode->direita = NULL;
    *raiz = newnode;
    } else {
        if (valor < (*raiz)->valor) {
            insertTree(&(*raiz)->esquerda, valor);
        } else {
            insertTree(&(*raiz)->direita, valor);
        }
    }  
}

void bfs(node* raiz) {
    if (raiz == NULL) {
        printf("Árvore vazia.\n");
        return;
    }
    Queue fila;
    initQueue(&fila);
    Enqueue(&fila, raiz);
    while (!isEmptyQueue(&fila)) {
        node* atual = (node*)Dequeue(&fila);
        printf("%d ", atual->valor);
        if (atual->esquerda != NULL) {
            Enqueue(&fila, atual->esquerda);
        }
        if (atual->direita != NULL) {
            Enqueue(&fila, atual->direita);
        }
    }
}

void destroyTree(node** raiz) {
    if (*raiz != NULL) {
        destroyTree(&(*raiz)->esquerda);
        destroyTree(&(*raiz)->direita);
        free(*raiz);
        *raiz = NULL;
    }
}

int isEmpty(node* raiz) {
    return raiz == NULL;
}

node* getMin(node* raiz) {
    if (raiz == NULL) return NULL;
    while (raiz->esquerda != NULL)
        raiz = raiz->esquerda;
    return raiz;
}


node* getMax(node* raiz) {
    if (raiz == NULL) return NULL;
    while (raiz->direita != NULL)
        raiz = raiz->direita;
    return raiz;
}

void printItem(node* raiz, int valor) {
    while (raiz != NULL)
    {
        if (valor < raiz->valor) {
            raiz = raiz->esquerda;
        } else if (valor > raiz->valor) {
            raiz = raiz->direita;
        } else {
            printf("Valor encontrado: %d\n", raiz->valor);
            return;
        }
    }
    printf("Valor nao encontrado.\n");
}

// FUNCOES AUXILIARES PARA IMPRESSAO VISUAL (NAO REQUISITAS NA ATIVADADE)

// Funcao auxiliar para desenhar na matriz
void preencherMatriz(node* raiz, char matriz[][80], int linha, int coluna, int deslocamento) {
    if (raiz == NULL) return;

    char buffer[10];
    sprintf(buffer, "[%d]", raiz->valor);
    int len = strlen(buffer);
    int start = coluna - (len / 2);

    // Escreve o no atual
    for (int i = 0; i < len; i++) {
        matriz[linha][start + i] = buffer[i];
    }

    // Desenha o caminho e o galho da ESQUERDA
    if (raiz->esquerda != NULL) {
        int pos_filho = coluna - deslocamento;
        for (int i = pos_filho + 1; i < start; i++) matriz[linha][i] = '_';
        matriz[linha + 1][pos_filho] = '/';
        preencherMatriz(raiz->esquerda, matriz, linha + 2, pos_filho, deslocamento / 2);
    }

    // Desenha o caminho e o galho da DIREITA
    if (raiz->direita != NULL) {
        int pos_filho = coluna + deslocamento;
        for (int i = start + len; i < pos_filho; i++) matriz[linha][i] = '_';
        matriz[linha + 1][pos_filho] = '\\';
        preencherMatriz(raiz->direita, matriz, linha + 2, pos_filho, deslocamento / 2);
    }
}

// Funcao principal de impressao visual
void printTreeVisual(node* raiz) {
    if (raiz == NULL) {
        printf("Arvore vazia.\n");
        return;
    }

    char matriz[20][80];
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 79; j++) {
            matriz[i][j] = ' ';
        }
        matriz[i][79] = '\0';
    }

    preencherMatriz(raiz, matriz, 0, 40, 16);

    for (int i = 0; i < 20; i++) {
        int linhaVazia = 1;
        for (int j = 0; j < 79; j++) {
            if (matriz[i][j] != ' ') {
                linhaVazia = 0;
                break;
            }
        }
        if (linhaVazia) break;

        int k = 78;
        while (k >= 0 && matriz[i][k] == ' ') {
            matriz[i][k] = '\0';
            k--;
        }
        printf("%s\n", matriz[i]);
    }
}