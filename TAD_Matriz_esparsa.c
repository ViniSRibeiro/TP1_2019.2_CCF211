//
// Created by vinicius on 18/09/2019.
//

#include "TAD_Matriz_esparsa.h"
#include <stdio.h>
#include <stdlib.h>
#include "celula_produto.h"
#include <locale.h>


void cria_matriz_esparsa(int m, int n, TMatriz_esparsa *mat){
    TCelula *aux_linhas, *aux_colunas;
    mat->primeiro = (TCelula*)malloc(sizeof(TCelula));
    mat->primeiro->linha = -1;
    mat->primeiro->coluna = -1;
    int i = 1, j = 1; //1 pois a primeira cabeça da linha e da coluna estao criadas
    mat->primeiro->prox_coluna = (TCelula*)malloc(sizeof(TCelula));
    mat->colunas = mat->primeiro->prox_coluna;
    mat->colunas->coluna= 0;
    mat->colunas->linha = -1;
    aux_colunas = mat->colunas;
    mat->primeiro->prox_linha = (TCelula*)malloc(sizeof(TCelula));
    mat->linhas = mat->primeiro->prox_linha;
    mat->linhas->linha = 0;
    mat->linhas->coluna = -1;
    aux_linhas = mat->linhas;

    for ( i; i < m; ++i) { // cria as cabeças das linhas
        aux_linhas->prox_linha = (TCelula*)malloc(sizeof(TCelula));
        aux_linhas->prox_linha->linha = i;
        aux_linhas->prox_linha->coluna = -1;
        aux_linhas = aux_linhas->prox_linha;
    }
    aux_linhas->prox_linha = mat->primeiro;
    /*criou todos os cabeçalhos de linhas */

    for ( j; j < n; ++j) { // cria as cabeças das colunas
        aux_colunas->prox_coluna = (TCelula*)malloc(sizeof(TCelula));
        aux_colunas->prox_coluna->coluna = i;
        aux_colunas->prox_coluna->linha = -1;
        aux_colunas = aux_colunas->prox_coluna;
    }
    aux_colunas->prox_coluna = mat->primeiro;
    /*criou todos os cabeçalhos de colunas*/
}

int insere_Item(Matriz_esparsa *mat, int linha, int coluna, TCelula* pCel){
    TCelula *aux_linha,*aux_coluna, Elelmento_E;
    aux_coluna = mat->colunas;
    while(aux_coluna->coluna != coluna){  //verificar esse operador mais tarde
        aux_coluna = aux_coluna->prox_coluna;
    } //encontrou a coluna correta
    aux_coluna = aux_coluna->prox_linha; // descendo pela coluna correta para encontrar o elemento anterior ao da inserçao
    while (aux_coluna->linha != linha){
        aux_coluna = aux_coluna->prox_linha;
    }// encontrou o elemento anterior na mesma coluna

    aux_linha = mat->linhas;
    while(aux_linha->linha != linha){
        aux_linha = aux_linha->prox_linha;
    } //encontrou a linha correta

    aux_linha= aux_linha->prox_coluna; // andando na linha correta para encontrar o elemento anterior
    while (aux_linha->coluna != coluna){
        aux_linha = aux_linha->prox_coluna;
    }// encontrou o elemento anterior na mesma linha

    Elelmento_E.prox_linha = aux_linha;

    Elelmento_E.prox_linha = (TCelula*)malloc(sizeof(TCelula));
    Elelmento_E.prox_coluna = aux_coluna;
    Elelmento_E = *pCel;
    aux_linha->prox_linha = &Elelmento_E;
    aux_coluna->prox_coluna = &Elelmento_E;

}

int quantidade_compras_cliente(Matriz_esparsa *mat, int linha) { //soma de toda uma linha
    int soma = 0;
    TCelula *aux_linha = mat->linhas;
     while(aux_linha->linha != linha){
        aux_linha = aux_linha->prox_linha;
    } // encontrou a linha correta

    while (aux_linha->prox_coluna->coluna != -1 ){
        soma = soma+ aux_linha->Lista_produtos.soma_qtd;
        aux_linha = aux_linha->prox_coluna;
    }
    printf("%d\n",soma);
    return 1;
}

int quantidade_compras_produto(Matriz_esparsa *mat, int coluna) { //soma toda uma coluna
    int soma = 0;
    TCelula *aux_coluna = mat->colunas;
    while(aux_coluna->coluna != coluna){
        aux_coluna=aux_coluna->prox_coluna;
    } //encontrou a coluna correta
    while (aux_coluna->prox_linha->linha != -1){
        soma = soma+ aux_coluna->Lista_produtos.soma_qtd;
    }
    printf("%d\n",soma);

}

int Print_Matriz(Matriz_esparsa *mat){
    TCelula *aux_linhas, *aux_colunas;
    int  i = 0;
    aux_linhas = mat->linhas;
    aux_colunas = aux_linhas->prox_coluna;

    while(aux_linhas != mat->primeiro) { //enquanto nao aponta para a cabeça da matriz novamente
        if(aux_linhas->prox_coluna == aux_linhas){ //imprimir uma coluna inteira de 0's
            aux_colunas =mat->primeiro->prox_coluna;
            while (aux_colunas != mat->primeiro){ // enquanto nao aponta para a cabeça da linha novamente
                printf("0\n");
                aux_colunas = aux_colunas->prox_coluna;
            }
        }else {
            while (aux_colunas != aux_linhas) { //enquanto a proxima coluna nao e a cabeça das linhas novamente
                if (aux_colunas->prox_coluna->coluna - aux_colunas->coluna >1) { //imprimir quantos 0's faltarem naquele local
                    for (i = 0; i < (aux_colunas->prox_coluna->coluna - aux_colunas->coluna); ++i) {
                        printf("0");
                    }
                } else {
                    printf("%d", aux_colunas->Lista_produtos.soma_qtd);
                }
                aux_colunas = aux_colunas->prox_coluna; //avança para a proxima coluna na mesma linha
            }
        }
        aux_linhas = aux_linhas->prox_linha; //avança para a proxima linha
        aux_colunas = aux_linhas->prox_coluna; //avança para o primeiro indice na linha seguinte
    }
}