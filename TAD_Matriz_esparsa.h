//
// Created by vinicius on 18/09/2019.
//
/*
 * Esse arquivo implementa os TADs da matriz esparsa e suas funçoes
 * utilizando as celulas projetadas em celula_produto.h
 */

#ifndef TP120192CCF211_CELULA_COMPRA_H
#define TP120192CCF211_CELULA_COMPRA_H

#include "celula_produto.h"
#endif //TP120192CCF211_CELULA_COMPRA_H

typedef struct Celula {
    struct Celula *prox_linha, *prox_coluna;
    int linha, coluna;
    Tlista_produto Lista_produtos;
} TCelula;

typedef struct{
    int m, n;
    TCelula *linhas, *colunas;
}TMatriz_esparsa;

typedef TMatriz_esparsa Matriz_esparsa;

void cria_matriz_esparsa(int m, int n, TMatriz_esparsa mat);
int inicia_Cel_Cabeca(Matriz_esparsa *mat);
int insere_Cel_CabecaLinha(Matriz_esparsa *mat);
int insere_Cel_CabecaColuna(Matriz_esparsa *mat);
int insere_Item(Matriz_esparsa *mat, int linha, int coluna, TCelula cel);
int Print_Matriz(Matriz_esparsa *mat);
int quantidade_compras_cliente(Matriz_esparsa *mat, int linha, TCelula *pCelula);
int quantidade_compras_produto(Matriz_esparsa *mat, int coluna, TCelula *pCelula);