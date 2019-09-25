//
// Created by vinicius on 18/09/2019.
//

#include "file_read.h"
#include <stdio.h>
#include <stdlib.h>
#include "TAD_Matriz_esparsa.h"
#include "celula_produto.h"
Matriz_esparsa read_matrix(char *nome){ //nome ou endereco do arquivo
    TMatriz_esparsa *pMat;
    Titem_produto *pItem;
    Tlista_produto *pLista;
    Tcel_produto *pCelproduto;
    TCelula *pCelMatriz;
    char linha[2];

    int m=0, n=0;
    int i=0, j=0;


    FILE *arquivo;

    arquivo = fopen(nome,"r");
    if (!arquivo){
        arquivo = fopen("arquivo.txt","w");
        fprintf(arquivo, "Erro ao abrir arquivo\n");
        fclose(arquivo);
        return 1;
    }

    fgets(linha,2, arquivo); //le primeira linha
    sscanf(linha, "%d %d", &m, &n);

    if (m<=0 || n<=0){
        return 0;
    }

    cria_matriz_esparsa(m, n, pMat);

    while(!feof(arquivo)){

        sscanf(linha, "%d %d", &i, &j); //le as coordenadas a ser inserida na matriz
        FLPVazia(pLista);
        while (!feof(arquivo)){
            fscanf("%c,%d", pItem->data, pItem->qtd);
        }
        insere_Item()
    }
    fclose(arquivo);
    return pMat;
}