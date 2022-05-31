#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "carrinho.h"
#define T 500
#include <time.h>

int main()
{
    int opc = 0, pos=0;
    char arquivo[51];
    item* p_carrinho[T];
    do {
        system("clear");
        printf(">>>>>   SUPERMERCADO FATEC  <<<<<\n");
        printf(">>    0. Abrir novo Carrinho   <<\n");
        printf(">>    1. Adicionar no Carrinho <<\n");
        printf(">>    2. Fechar Carrinho       <<\n");
        printf(">>    3. Imprimir Nota         <<\n");
        printf(">>    9. S A I R               <<\n");
        printf(">>>>> Entre com Sua opção:     <<\n");
        printf(">>>>> ");

        scanf("%d", &opc);
        switch(opc){
            case 0:
                inicializar(p_carrinho, T);
                printf("Carrinho novo Aberto - Emitindo nota \n");
                __fpurge(stdin);
                printf("Pressione uma tecla....");
                getchar();
                break;
            case 1:
                int adicionou = adicionar(p_carrinho, pos);
                if(adicionou) pos++;
                break;
            case 2:
                fecharCompra(p_carrinho, pos, &arquivo[0]);
                printf("Arquivo: %s\n", arquivo);
                __fpurge(stdin);
                printf("Pressione uma tecla....");
                getchar();
                break;
            case 3:
                printf("Arquivo salvo no disco: %s \n", arquivo);
                char comando[1024] = {'\0'};
                strcpy(comando, "libreoffice --convert-to \"pdf\" ");
                strcat(comando, arquivo);
                system(comando);
                printf("Tamanho: %d \n", strlen(arquivo));
                arquivo[strlen(arquivo) - 3] = 'p';
                arquivo[strlen(arquivo) - 2] = 'd';
                arquivo[strlen(arquivo) - 1] = 'f';
                strcpy(comando, " evince ");
                strcat(comando, arquivo);
                printf("%s \n",comando);
                system(comando);
                __fpurge(stdin);
                printf("Pressione uma tecla....");
                getchar();
                break;
            case 9:
                printf("Fim do programa\n");
                break;
            default:
                printf("Opcao invalida \n");
                 __fpurge(stdin);
                printf("Pressione uma tecla....");
                getchar();
                break;

        }
    }while(opc!=9);
    return 0;
}
