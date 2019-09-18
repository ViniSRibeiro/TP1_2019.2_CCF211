//
// Created by vinicius on 18/09/2019.
//
/*
 *Arquivo que implementa as funcoes da lista encadeada simples dentro da celula da matriz esparsa
 */
#include <stddef.h>
#include "celula_produto.h"
#include <stdlib.h>

void FLVazia(Tlista_produto* pLproduto)
{
    pLproduto->pPrimeiro = (Apontador) malloc(sizeof(Tlista_produto));
    pLproduto->pUltimo = pLproduto->pPrimeiro;
    pLproduto->pPrimeiro->Pprox = NULL;
}

int LPEhVazia(Tlista_produto* pLproduto){
    return (pLproduto->pPrimeiro == pLproduto->pUltimo);
}

int LPInsere(Tlista_produto* pLproduto, Titem_produto* pIproduto){
    pLproduto->pUltimo->Pprox = (Apontador) malloc(sizeof(Tcel_produto));
    pLproduto->pUltimo = pLproduto->pUltimo->Pprox;
    pLproduto->pUltimo->Item = *pIproduto;
    pLproduto->pUltimo->Pprox = NULL;
    pLproduto->soma_datas++;
    pLproduto->soma_qtd++;
}

