// NEcessario reescrever e adicionar as funcoes de fila
// Para o trabalho, as funcoes principais são: initTree, insertTree, bfs, getMin, getMax e destroyTree








#include <stdio.h>
#include "tree.h"

void imprimirMenu() {
    printf("##################################################\n");
    printf("##    GENERIC BINARY SEARCH TREE                ##\n");
    printf("##    (ARVORE BINARIA GENERICA DE BUSCA)        ##\n");
    printf("##################################################\n");
    printf("##    [Selecione uma operacao]                  ##\n");
    printf("##  1 - Insert Node                             ##\n");
    printf("##  2 - Breadth Search (Busca em Largura)       ##\n");
    printf("##  3 - Print Item                              ##\n");
    printf("##  4 - Get MIN / MAX                           ##\n");
    printf("##  5 - Print Tree (visual)                     ##\n");
    printf("##  6 - Depth Search (In Order)                 ##\n");
    printf("##  7 - Depth Search (Pre Order)                ##\n");
    printf("##  8 - Depth Search (Post Order)               ##\n");
    printf("##  9 - Depth Search (Pre order Interativo)     ##\n");
    printf("##  10 - Depth Search (In order Interativo)     ##\n");
    printf("##  11 - Depth Search (Post order Interativo)   ##\n");
    printf("##  12 - Exit                                   ##\n");
    printf("##################################################\n");
}

int main() {
    node* raiz;
    initTree(&raiz);
    int opcao, valor;

    do {
        imprimirMenu();
        printf("Digite a opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                insertTree(&raiz, valor);
                break;
            case 2:
                bfs(raiz);
                printf("\n");
                break;
            case 3:
                printf("Digite o valor a buscar: ");
                scanf("%d", &valor);
                printItem(raiz, valor);
                break;
            case 4:
                if (raiz != NULL) {
                    printf("MIN: %d\n", getMin(raiz)->valor);
                    printf("MAX: %d\n", getMax(raiz)->valor);
                } else {
                    printf("Arvore vazia.\n");
                }
                break;
            case 5:
                printf("\n");
                printTreeVisual(raiz);
                printf("\n");
                break;
            case 6:
                inOrder(raiz);
                printf("\n");
                break;
            case 7:
                preOrder(raiz);
                printf("\n");
                break;
            case 8:
                postOrder(raiz);
                printf("\n");
                break;
            case 9:
                preOrderInterativo(raiz);
                printf("\n");
                break;
            case 10:
                inOrderInterativo(raiz);
                printf("\n");
                break;
            case 11:
                postOrderInterativo(raiz);
                printf("\n");
                break;
            case 12:
                destroyTree(&raiz);
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 12);

    return 0;
}