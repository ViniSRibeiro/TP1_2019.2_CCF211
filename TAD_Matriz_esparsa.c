//
// Created by vinicius on 18/09/2019.
//

#include "TAD_Matriz_esparsa.h"
#include <stdio.h>
#include <stdlib.h>
#include "celula_produto.h"

Matriz_esparsa *cria_matriz_esparsa(int m, int n){
    Matriz_esparsa *mat;
    mat = (Matriz_esparsa *)malloc(sizeof(Matriz_esparsa));

    if (!mat || m<=0 || n<=0){
        return 0;
    }

    mat->start = NULL;
    mat->end_linha = NULL;
    mat->end_coluna = NULL;
    mat->m = m;
    mat->n = n;

    inicia_Cel_Cabeca(mat);

    return mat;
}

int inicia_Cel_Cabeca(Matriz_esparsa *mat) {
    int i = 0;

    TCelula *cabeca;
    cabeca = (TCelula *) malloc(sizeof(TCelula));

    if (!cabeca) {
        return 0;
    }

    cabeca->coluna = -1;
    cabeca->linha = -1;

    mat->start = cabeca;
    mat->end_linha = cabeca;
    mat->end_coluna = cabeca;

    for (i = 1; i <= mat->n; i++) {
        insere_Cel_CabecaColuna(mat);
    }
    for (i = 1; i <= mat->m; i++) {
        insere_Cel_CabecaLinha(mat);
    }
    return 1;
}

int insere_Cel_CabecaColuna(Matriz_esparsa *mat){
    TCelula *cabeca;
    cabeca = (TCelula*)malloc(sizeof(TCelula));

    if (!cabeca){
        return 0;
    }

    cabeca->coluna = -1;
    cabeca->linha = 0;

    mat->end_coluna->prox_coluna = cabeca;
    mat->end_coluna = cabeca;

    cabeca->prox_coluna = mat->start;
    cabeca->prox_linha = cabeca;
    return 1;
}

int insere_Cel_CabecaLinha(Matriz_esparsa *mat){
    TCelula *cabeca;
    cabeca = (TCelula*)malloc(sizeof(TCelula));

    if (!cabeca){
        return 0;
    }

    cabeca->coluna = 0;
    cabeca->linha = -1;

    mat->end_linha->prox_linha = cabeca;
    mat->end_linha = cabeca;

    cabeca->prox_linha = mat->start;
    cabeca->prox_coluna = cabeca;

    return 1;
}

int insere_Item(Matriz_esparsa *mat, int linha, int coluna, Titem_produto pItem){
    int i;

    if (!mat || mat->m <= 0 || mat->n <= 0){
        return 0;
    }
    if (linha>mat->m || coluna>mat->n || linha < 1 || coluna < 1){
        return 0;
    }

    TCelula *pCelula; //celula temporaria
    TCelula *pCelulaColuna; //celula temporaria para coluna
    TCelula *pCelulaLinha; //celula temporaria para linha

    pCelula = (TCelula*)malloc(sizeof(TCelula));

    if (!pCelula){ //memoria cheia
        return 0;
    }

    pCelula->linha = linha;
    pCelula->coluna = coluna;
    pCelula->Cel_produtos = ;

    pCelulaLinha = mat->start->prox_linha; //primeira cabeça so de linhas
    pCelulaColuna = mat->start->prox_coluna; //primeira cabeça so de colunas

    //Percorre ate a linha desejada
    for (i=0; i<linha-1; i++){
        pCelulaLinha = pCelulaLinha->prox_linha;
    }

    i=0;
    while (i<coluna && pCelulaLinha->linha != -1){
        if (pCelulaLinha->prox_coluna->coluna > pCelula->coluna){ //se fica a esquerda
            pCelula->prox_coluna = pCelulaLinha->prox_coluna;
            pCelulaLinha->prox_coluna = pCelula;
        }
        else{
            pCelulaLinha = pCelulaLinha->prox_coluna; //percorre pela direita
        }
        i++;
    }
    if (pCelulaLinha->prox_coluna->linha == -1){ //a celula esta mais a direita
        pCelula->prox_coluna = pCelulaLinha->prox_coluna; //aponta para a cabeca
        pCelulaLinha->prox_coluna = pCelula; //ultima celula ou cabeca, senao tiver celulas, aponta para a celula
    }
    //linha encontrada e apontada

    //buscar a coluna
    //Percorre ate a coluna do elemento, percorre nas cabecas ate a informada
    for (i = 0; i < coluna-1; i++){
        pCelulaColuna = pCelulaColuna->prox_coluna; //percorre a direita (colunas) ate achar a correta
    }
    i=0;
    while (i<linha && pCelulaColuna->prox_linha->coluna != -1){ //anda pelas celulas ate achar a posicao
        if (pCelulaColuna->prox_linha->linha > pCelula->linha){
            pCelula->prox_linha = pCelulaColuna->prox_linha;
            pCelulaColuna->prox_linha = pCelula;
        }
        else{
            pCelulaColuna = pCelulaColuna->prox_linha; //anda pelas celulas abaixo
        }
        i++;
    }
    if (pCelulaColuna->prox_linha->coluna == -1){
        pCelula->prox_linha = pCelulaColuna->prox_linha; //aponta para a cabeca
        pCelulaColuna->prox_linha = pCelula; //ultima celula ou cabeca, senao tiver celulas, aponta para a celula
    }
    return 1;
}

int Print_Matriz(Matriz_esparsa *mat){
    int i, j;
    TCelula *pCelula;

    if (!mat || !mat->m || !mat->n){
        return 0;
    }

    pCelula = mat->start->prox_linha;

    printf("\n");

    for (i = 1; i <= mat->m; i++){
        for (j = 1; j <= mat->n; j++){
            if (pCelula->prox_coluna->linha == i && pCelula->prox_coluna->coluna == j){
                pCelula = pCelula->prox_coluna;
                printf("  \t%0.2f   ", pCelula->Lista_produtos->soma_qtd);
            }
            else{
                printf("  \t%0.2f   ", 0.0F);
            }
        }
        printf("\n");
        pCelula = pCelula->prox_coluna->prox_linha;
    }

    return 1;
}

int quantidade_compras_cliente(Matriz_esparsa *mat, int linha, TCelula *pCelula) {
    int soma = 0;
     pCelula = mat->start->prox_linha;
     while(pCelula->linha != linha){
        pCelula = pCelula->prox_linha;
    }
    while (pCelula->prox_coluna!= NULL){
        soma = soma+ pCelula->Lista_produtos->soma_qtd;
    }
    printf("%d\n",soma);



}

int quantidade_compras_produto(Matriz_esparsa *mat, int coluna, TCelula *pCelula) {
    int soma = 0;
    pCelula = mat->start->prox_coluna;
    while(pCelula->linha != coluna){
        pCelula = pCelula->prox_coluna;
    }
    while (pCelula->prox_linha!= NULL){
        soma = soma+ pCelula->Lista_produtos->soma_qtd;
    }
    printf("%d\n",soma);



}