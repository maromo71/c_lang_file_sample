#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <time.h>
#include "carrinho.h"
void preparardata(char *nomearq){
    time_t t;   // not a primitive datatype
    time(&t);
    strcpy(nomearq, "arq_");
    strcat(nomearq, ctime(&t));
    for(int i=0; i<strlen(nomearq);i++){
        if(nomearq[i]==' ' || nomearq[i]=='\n')nomearq[i]='_';
    }
    strcat(nomearq, ".txt");
    printf("%s\n", nomearq);
}

void inicializar(item* p_carrinho[], int tam){
    for(int i = 0; i<tam; i++) p_carrinho[i] = NULL;
}

int adicionar(item* p_carrinho[], int pos){
    int codigoComp, cod, qtd;
    char desc[51];
    float preco;

    printf("Codigo produto comprado: \n");
    scanf("%d", &codigoComp);
    FILE *fp = fopen("produtos.txt", "r");
    while((fscanf(fp, "%d%s%f", &cod, desc, &preco))!=EOF){
        if(cod==codigoComp){
            printf("Código encontrado: %d \n", cod);
            printf("Produto: %s \n", desc);
            printf("Preço: %.2f \n", preco);
            printf("Digite a quantidade comprada: \n");
            scanf("%d", &qtd);
            p_carrinho[pos] = (item*)malloc(sizeof(item));
            p_carrinho[pos]->codigo = cod;
            strcpy(p_carrinho[pos]->descricao, desc);
            p_carrinho[pos]->valorUnitario = preco;
            p_carrinho[pos]->quantidade = qtd;
            p_carrinho[pos]->valorTotal = qtd * preco;
            printf("Lançado no carrinho..\n");
            __fpurge(stdin);
            printf("Pressione uma tecla...");
            getchar();
            return 1;
        }
    };
    printf("Produto nao cadastrado \n");
    return 0;
}

void fecharCompra(item *p_carrinho[], int tam, char * arquivo){
    srand(time(NULL));
    char nomearq[101] = {'\0'};
    preparardata(nomearq);

    FILE *fp = fopen(nomearq, "w");

    double total = 0;
    printf("Codigo  Descrição             Valor Unitario      Qtd     Valor Total \n");
    fprintf(fp, "=======================================================================\n");
    fprintf(fp, ">>>>>>>>>>>>>> S U P E R M E R C A D O    D A   F A T E C <<<<<<<<<<<<<\n");
    fprintf(fp, "=======================================================================\n");
    fprintf(fp,"Nota emitida Num: %d\nArquivada como: %s \n\n",rand()%1000, nomearq);
    fprintf(fp, "Codigo  Descrição             Valor Unitario      Qtd     Valor Total \n\n");

    printf("-----------------------------------------------------------------------\n");
    fprintf(fp, "-----------------------------------------------------------------------\n");
    for(int i=0; i<tam; i++){
        printf("Item: %d\n", i+1);
        fprintf(fp, "Item: %d\n", i+1);
        printf("-------\n");
        fprintf(fp, "-------\n");
        printf("%6d %-21s %15.2f %8d %17.2f\n", p_carrinho[i]->codigo,
            p_carrinho[i]->descricao, p_carrinho[i]->valorUnitario, p_carrinho[i]->quantidade,
            p_carrinho[i]->valorTotal);
        fprintf(fp, "%6d %-21s %15.2f %8d %17.2f\n", p_carrinho[i]->codigo,
            p_carrinho[i]->descricao, p_carrinho[i]->valorUnitario, p_carrinho[i]->quantidade,
            p_carrinho[i]->valorTotal);
        total+= p_carrinho[i]->valorTotal;

    }
    printf("=======================================================================\n");
    fprintf(fp, "=======================================================================\n");
    printf("Valor da nota fiscal: %.2f \n", total);
    fprintf(fp, "Valor da nota fiscal: %.2f \n", total);
    printf("=======================================================================\n");
    fprintf(fp,"=======================================================================\n");
    fclose(fp);
    strcpy(arquivo, nomearq);
}
