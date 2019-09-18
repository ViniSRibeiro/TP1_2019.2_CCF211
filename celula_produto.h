//
// Created by vinicius on 18/09/2019.
//
/*
 * Arquivo que descreve os TADs da lista encadeada
 *Implementada  dentro das celulas da matriz esparsa
 * e suas funçoes
 */

/*Talvez nao seja necessario detalhar tanto os itens da celula, verificar na monitoria*/
#ifndef TP120192CCF211_CELULA_PRODUTO_H
#define TP120192CCF211_CELULA_PRODUTO_H

/*talvez seja necessario formatar datas, verificar mais tarde*/
#endif //TP120192CCF211_CELULA_PRODUTO_H
typedef struct {
    char data[10];
    int qtd;
}Titem_produto;

typedef struct cel_produto* Apontador;
typedef struct cel_produto{
    Titem_produto Item;
    struct cel_produto *Pprox;
}Tcel_produto;

typedef  struct {
    Apontador pPrimeiro;
    Apontador pUltimo;
    int soma_datas; //quantas ocasioes diferente o produto foi comprado pelo mesmo cliente
    int soma_qtd; //quantas unidades diferentes do produto foi comprado pelo mesmo cliente
}Tlista_produto;

void FLPVazia(Tlista_produto* pLproduto);
int LPEhVazia(Tlista_produto* pLproduto);
int LPInsere(Tlista_produto* pLproduto, Titem_produto* pIproduto);
/*caso necessario, adcionar funçao de remoçao*/
