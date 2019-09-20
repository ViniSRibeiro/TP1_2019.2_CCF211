//
// Created by vinicius on 18/09/2019.
//

#include "TAD_Matriz_esparsa.h"
#include <stdio.h>
#include <stdlib.h>
#include "celula_produto.h"

void cria_matriz_esparsa(int m, int n, TMatriz_esparsa mat){
    for (int i = 0; i <m ; ++i) {
        mat.linhas = (TCelula *) malloc(sizeof(TMatriz_esparsa));
        mat.colunas = &mat;
        mat.m = i;
        mat.n = 0;

    }

}

int insere_Item(Matriz_esparsa *mat, int linha, int coluna, TCelula* pCel){
    TCelula aux_linha,aux_coluna;
    aux_coluna.prox_coluna = mat->colunas->prox_coluna;
    while(aux_coluna.prox_coluna->coluna != coluna){
        aux_coluna.prox_coluna = mat->colunas->prox_coluna;
    } //encontrou a coluna correta
    aux_coluna.prox_linha = aux_coluna.prox_coluna->prox_linha; // descendo pela coluna correta para encontrar o elemento anterior ao da inserçao
    while (aux_coluna.prox_linha->linha < linha){
        aux_coluna.prox_linha = aux_coluna.prox_linha->prox_linha;
    }// encontrou o elemento anterior na mesma coluna

    aux_linha.prox_linha = mat->colunas->prox_linha;
    while(aux_linha.prox_linha->linha != linha){
        aux_linha.prox_linha = mat->linhas->prox_linha;
    } //encontrou a linha correta

    aux_coluna.prox_linha = aux_coluna.prox_coluna->prox_linha; // andando na linha correta para encontrar o elemento anterior
    while (aux_linha.prox_coluna->coluna < coluna){
        aux_linha.prox_coluna = aux_linha.prox_coluna->prox_coluna;
    }// encontrou o elemento anterior na mesma linha

    aux_linha.prox_coluna->prox_coluna = (TCelula*)malloc(sizeof(TCelula));
    aux_linha.prox_coluna->prox_linha = aux_coluna.prox_linha->prox_linha;
    aux_linha.prox_coluna = pCel;




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
     pCelula = mat->colunas;
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