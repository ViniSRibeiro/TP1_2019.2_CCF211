//
// Created by vinicius on 18/09/2019.
//

#include "file_read.h"
#include <stdio.h>
#include <stdlib.h>
#include "TAD_Matriz_esparsa.h"
#include "celula_produto.h"
Matriz_esparsa *read_matrix(char *nome){ //nome ou endereco do arquivo
    Matriz_esparsa *mat;
    Titem_produto *Item;

    char linha;

    int m=0, n=0;
    int l=0, c=0;
    float valor=0.0;

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

    mat = cria_matriz_esparsa(m, n);

    while(fgets(linha, arquivo)!= '\n'){
        sscanf(linha, "%d %d", &l, &c);
        sscanf(linha, "%s %d",Item->data,Item->qtd);

        if (Item->qtd){
            insere_Item(mat, l, c, Item);
        }
    }
    fclose(arquivo);
    return mat;
}