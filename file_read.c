//
// Created by vinicius on 18/09/2019.
//

#include "file_read.h"
#include <stdio.h>
#include <stdlib.h>
#include "TAD_Matriz_esparsa.h"
#include "celula_produto.h"
Matriz_esparsa *read_matrix(char *nome){ //nome ou endereco do arquivo
    TMatriz_esparsa *mat;
    Titem_produto *Item;
    Tlista_produto lista;
    Tcel_produto *Celproduto;
    TCelula *CelMatriz;
    char linha;

    int m=0, n=0;
    int i=0, j=0;


    FILE *arquivo;

    arquivo = fopen(nome,"r");
    if (!arquivo){
        arquivo = fopen("arquivo.txt","w");
        fprintf(arquivo, "Erro ao abrir arquivo\n");
        fclose(arquivo);
        return NULL;
    }

    fgets(linha, arquivo); //le primeira linha
    sscanf(linha, "%d %d", &m, &n);

    if (m<=0 || n<=0){
        return 0;
    }

    cria_matriz_esparsa(m,n, mat);

    while(fgets(linha,2, arquivo)!= '\n'){
        sscanf(linha, "%d %d", &i, &j);
        FLPVazia(lista);
        while (arquivo != '\n'){ //pesquisar estrutura de repetiçao apropriada
            sscanf("%s,%d",Celproduto->Item.data,Celproduto->Item.qtd);
            LPInsere(lista,Celproduto);
        }
        CelMatriz->Lista_produtos = lista;
        insere_Item(mat,m,n,CelMatriz);
    }
    fclose(arquivo);
    return mat;
}