#include <stdio.h>
#include <locale.h>
#include "TAD_Matriz_esparsa.h"
#include "celula_produto.h"
#include "file_read.h"
#include <stdlib.h>
int main() {
    setlocale(LC_ALL, "Portuguese");
    TMatriz_esparsa mat,*pMat = &mat;
    Titem_produto Item, *pItem = &Item;
    Tlista_produto Lista,*pLista = &Lista;
    /*Tcel_produto Celproduto;*/
    /*Celula CelMatriz;*/
    char linha[2];

    int linha_tam_matriz=0, coluna_tam_matriz=0;
    int linha_insere=0, coluna_insere=0,linha_le = 0,coluna_le = 0;
    int opcao;

    printf(" --------------------------------------------------------- \n");
    printf("|                       UFV - CAF                         |\n");
    printf("|                         TP 1                            |\n");
    printf("|            Filipe Fonseca Lacerda -  3502               |\n");
    printf("|            Vinicius Ribeiro       -  2670               |\n");
    printf("|            William Lucas Araujo   -  3472               |\n");
    printf(" --------------------------------------------------------- \n");

    do{
        printf(" --------------------------------------------------------- \n");
        printf("|                       OPERACOES                         |\n");
        printf("|                                                         |\n");
        printf("|  1 - Imprimir Matriz                                    |\n");
        printf("|  2 - Leitura da Matriz                                  |\n");
        printf("|  3 - Compras por cliente                                |\n");
        printf("|  4 - Compras por produto                                |\n");
        printf("|  5 - Sair                                               |\n");
        printf(" --------------------------------------------------------- \n");

        printf("Entre com uma opcao: ");
        scanf("%d",&opcao);

        switch(opcao)
        {
            case 1:
                /*system("CLS"); - Windows*/
                system("clear");
                printf("Matriz:\n");
                break;

            case 2:
                system("clear");
                printf("Leitura da Matriz:\n");
                FILE *arquivo;

                arquivo = fopen(arquivo,"r");
                if (!arquivo){
                    arquivo = fopen("arquivo.txt","w");
                    fprintf(arquivo, "Erro ao abrir arquivo\n");
                    fclose(arquivo);
                    return 1;
                }

                fgets(linha,2, arquivo); //le primeira linha
                sscanf(linha, "%d %d", &linha_tam_matriz, &coluna_tam_matriz);

                if (linha_tam_matriz <= 0 || coluna_tam_matriz <= 0){
                    return 0;
                }

                cria_matriz_esparsa(linha_tam_matriz, coluna_tam_matriz, pMat);

                while(!feof(arquivo)){

                    sscanf(linha, "%d %d", &linha_insere, &coluna_insere); //le as coordenadas a ser inserida na matriz
                    FLPVazia(pLista);
                    while (!feof(arquivo)){
                        fscanf("%c,%d", Item.data,Item.qtd);
                        LPInsere(pLista,pItem);
                    }
                    insere_Item(pMat,linha_insere,coluna_insere,pLista);
                }
                fclose(arquivo);
                break;

            case 3:
                system("clear");
                printf("Compras por Cliente:(leitura de uma linha)\n");
                printf("digite o numero da linha\n");
                scanf("%d",&linha_le);
                quantidade_compras_cliente(pMat,linha_le);
                break;

            case 4:
                system("clear");
                printf("Compras por Produto:(leitura de uma coluna)\n");
                printf("digite o numero da coluna\n");
                scanf("%d",&coluna_le);
                quantidade_compras_produto(pMat,coluna_le);
                break;

            case 5:
                break;

        }
    }while(opcao != 5);


    return 0;
}