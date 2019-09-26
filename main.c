#include <stdio.h>
#include <locale.h>
#include "TAD_Matriz_esparsa.h"
#include <stdlib.h>
#include <string.h>
int main() {
    setlocale(LC_ALL, "Portuguese");
    TMatriz_esparsa mat, *pMat = &mat;
    Titem_produto Item, *pItem = &Item;
    Tlista_produto Lista, *pLista = &Lista;
    /*Tcel_produto Celproduto;*/
    /*Celula CelMatriz;*/
    char linha[1000000], *pPalavra,*pFrase;

    int tam_matriz[2],linhas_tam_matriz,colunas_tam_matriz, *pTam_matriz = &tam_matriz;
    int linha_insere = 0, coluna_insere = 0, linha_le = 0, coluna_le = 0;
    int opcao = 0;
    int contador_pLinha= 0;
    tam_matriz[0] = 4;
    tam_matriz[1] = 4;
    printf(" --------------------------------------------------------- \n");
    printf("|                       UFV - CAF                         |\n");
    printf("|                         TP 1                            |\n");
    printf("|            Filipe Fonseca Lacerda -  3502               |\n");
    printf("|            Vinicius Ribeiro       -  2670               |\n");
    printf("|            William Lucas Araujo   -  3472               |\n");
    printf(" --------------------------------------------------------- \n");

    do {
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
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                /*system("CLS"); - Windows*/
                system("clear");
                printf("Matriz:\n");
                Print_Matriz(pMat);
                opcao = 0;

            case 2:
                system("clear");
                printf("Leitura da Matriz:\n");
                FILE *archive;

                archive = fopen("arquivo.txt", "r");
                if (archive == NULL) {
                    printf("erro ao abrir arquivo");
                    fclose(archive);
                } else { printf("arquivo aberto!\n");}


                /*for (int i = 0; i < 2; ++i) {
                    tam_matriz[i] = getc(archive);
                    /tam_matriz[i] = tam_matriz[i] -48;
                }*/
                fscanf(archive,"%d %d\n",&tam_matriz[0],&tam_matriz[1]);
                printf("tamanho da matriz:%d %d\n", tam_matriz[0], tam_matriz[1]);
                if (tam_matriz[0] <= 0 || tam_matriz[1] <= 0) {
                    printf("matriz inexistente");
                    break;
                }

                cria_matriz_esparsa(tam_matriz[0], tam_matriz[1], pMat);
                pFrase = fgets(linha, sizeof(linha), archive);
                printf("print da pFrase:%s",pFrase);
                while (pFrase != NULL) {
                    contador_pLinha = 0;
                    printf("%s\n", linha);
                    FLPVazia(pLista);
                    pPalavra = strtok(pFrase, " "); //erro e aqui
                    while(pPalavra != NULL) {
                        printf("pFrase possui %s\n",pFrase);
                        if (contador_pLinha == 0) {
                            linha_insere = (int)(*pPalavra);
                            linha_insere = linha_insere -48;
                            printf("%d\n",linha_insere);
                        } else {
                            if (contador_pLinha == 1) {
                                coluna_insere = (int)(*pPalavra);
                                coluna_insere = coluna_insere-48;
                                printf("%d\n",coluna_insere);
                            } else {
                                if (contador_pLinha %2 == 0) {
                                    strcpy(pItem->data, pPalavra);
                                    printf("data:%s\n",pItem->data);
                                } else {
                                    printf("pPalavra possui %d para alocar quantidade\n", *pPalavra-48);
                                    pItem->qtd = (int)(*pPalavra);
                                    pItem->qtd = pItem->qtd-48;
                                    printf("quantidade:%d\n",pItem->qtd);
                                    LPInsere(pLista, pItem);
                                    printf("pItem inseriu: %s %d\n",pItem->data,pItem->qtd);
                                }
                            }
                        }
                        contador_pLinha++;
                        printf("contador:%d\n",contador_pLinha);
                        pPalavra = strtok(NULL, " ");
                        printf("o pPalavra recebeu %s\n",pPalavra);
                        if(pPalavra == NULL){
                            printf("entrou no if do NULL");
                            if(pLista){
                                printf("foi inserir a lista");
                                insere_Item(pMat, linha_insere, coluna_insere, pLista);
                                printf("inseriu a lista na celula\n");
                            }
                            pFrase = fgets(linha, sizeof(linha), archive);
                            pPalavra = strtok(pFrase, " ");

                        }
                    }
                    printf("print da pFrase:%s",pFrase);
                    printf("Proximo e o Fgets");
                   //pFrase = fgets(linha, sizeof(linha), archive);


                }


                fclose(archive);
                opcao = 0;

            case 3:
                system("clear");
                printf("Compras por Cliente:(leitura de uma linha)\n");
                printf("digite o numero da linha\n");
                scanf("%d", &linha_le);
                quantidade_compras_cliente(pMat, linha_le);
                opcao = 0;

            case 4:
                system("clear");
                printf("Compras por Produto:(leitura de uma coluna)\n");
                printf("digite o numero da coluna\n");
                scanf("%d", &coluna_le);
                quantidade_compras_produto(pMat, coluna_le);
                opcao = 0;

            default:
                break;

        }
    }
     while (opcao != 5);


    return 0;
}