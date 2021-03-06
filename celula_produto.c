//
// Created by vinicius on 18/09/2019.
//
/*
 *Arquivo que implementa as funcoes da lista encadeada simples dentro da celula da matriz esparsa
 */
#include <stddef.h>
#include "celula_produto.h"
#include <stdlib.h>
#include <stdio.h>

void FLPVazia(Tlista_produto* pLproduto)
{
    pLproduto->pPrimeiro = (Tcel_produto*) malloc(sizeof(Tcel_produto));
    pLproduto->pUltimo = pLproduto->pPrimeiro;
    pLproduto->pUltimo->Pprox = NULL;
}

int LPEhVazia(Tlista_produto* pLproduto){
    return (pLproduto->pPrimeiro == pLproduto->pUltimo);
}

int LPInsere(Tlista_produto* pLproduto, Titem_produto* pIproduto){
    pLproduto->pUltimo->Pprox = (Apontador_produto) malloc(sizeof(Tcel_produto));
    pLproduto->pUltimo = pLproduto->pUltimo->Pprox;
    pLproduto->pUltimo->Item = *pIproduto;
    pLproduto->pUltimo->Pprox = NULL;
    pLproduto->soma_datas++;
    pLproduto->soma_qtd = pLproduto->soma_qtd + pLproduto->pUltimo->Item.qtd;
    return 0;
}

void LPImprime(Tlista_produto* pLista)
{
    Apontador_produto pAux;
    pAux = pLista->pPrimeiro->Pprox;
    while (pAux != NULL)
    {
        printf("%s\n", pAux->Item.data);
        printf("%d\n",pAux->Item.qtd);
        pAux = pAux->Pprox;
    }
}