#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

typedef struct Item
{
    char nome[20];
    char tipo[20];
    int quantidade;
} Item;


typedef struct Mochila
{
    Item* Item;
    int quantidade;
    int capacidade;
} Mochila;

int main() {
    SetConsoleOutputCP(65001);

    int opcao = -1;

    struct Mochila mochila;
    mochila.quantidade = 0;
    mochila.capacidade = 10;
    mochila.Item = (Item*) malloc(mochila.capacidade * sizeof(Item));

    while (opcao != 0) {
        printf("=====================================\n");
        printf("     MOCHILA DE SOBREVIVÊNCIA     \n");
        printf("=====================================\n");

        printf("itens da mochilha: %d/%d\n", mochila.quantidade, mochila.capacidade);
        printf("1. Adicionar um item\n");
        printf("2. Remover um item\n");
        printf("3. Listar todos os itens\n");
        printf("4. Buscar item por nome\n");
        printf("0. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
        case 1:
            printf("---- Adicionar um item ---\n");
            if (mochila.quantidade < mochila.capacidade) {
                Item novoItem;
                printf("Digite o nome do item: ");
                scanf("%s", novoItem.nome);
                printf("Digite o tipo do item: ");
                scanf("%s", novoItem.tipo);
                printf("Digite a quantidade do item: ");
                scanf("%d", &novoItem.quantidade);

                mochila.Item[mochila.quantidade] = novoItem;
                mochila.quantidade++;

                printf("Item adicionado com sucesso!\n\n");
            } else {
                printf("A mochila está cheia! Não é possível adicionar mais itens.\n");
            }
            break;
        case 2:
            if (mochila.quantidade > 0) {
            char nomeProcurado[20];
            int achou = 0;

            printf("\nDigite o nome do item que deseja remover: ");
            scanf("%s", nomeProcurado);

            for (int i = 0; i < mochila.quantidade; i++) {
                if (strcmp(mochila.Item[i].nome, nomeProcurado) == 0) {
                    
                    for (int j = i; j < mochila.quantidade - 1; j++) {
                        mochila.Item[j] = mochila.Item[j + 1];
                    }

                    mochila.quantidade--;
                    achou = 1;
                    printf("Item '%s' removido com sucesso!\n", nomeProcurado);
                    break;
                }
            }

            if (!achou) {
                printf("Item '%s' nao encontrado na mochila.\n", nomeProcurado);
                    }
            } else {
                printf("A mochila esta vazia!\n");
            }
             break;
        case 3:
            printf("\n=============================================\n");
            printf("           CONTEÚDO DA MOCHILA              \n");
            printf("=============================================\n");
            
            if (mochila.quantidade == 0) {
                printf("       [ A mochila está vazia ]             \n");
            } else {
                printf("%-3s | %-15s | %-10s | %-5s\n", "ID", "NOME", "TIPO", "QTD");
                printf("---------------------------------------------\n");

                for (int i = 0; i < mochila.quantidade; i++) {
                    printf("%02d  | %-15s | %-10s | %d\n", 
                            i + 1, 
                            mochila.Item[i].nome, 
                            mochila.Item[i].tipo, 
                            mochila.Item[i].quantidade);
                }
            }
            printf("=============================================\n\n");
            
            printf("Pressione ENTER para voltar ao menu...");
            getchar();
            getchar();
            break;
         case 4:
            printf("---- Buscar item por nome ---\n");
            if (mochila.quantidade > 0) {
                char nomeProcurado[20];
                int achou = 0;

                printf("Digite o nome do item que deseja buscar: ");
                scanf("%s", nomeProcurado);

                for (int i = 0; i < mochila.quantidade; i++) {
                    if (strcmp(mochila.Item[i].nome, nomeProcurado) == 0) {
                        printf("Item encontrado:\n");
                        printf("Nome: %s\n", mochila.Item[i].nome);
                        printf("Tipo: %s\n", mochila.Item[i].tipo);
                        printf("Quantidade: %d\n", mochila.Item[i].quantidade);
                        achou = 1;
                        break;
                    }
                }

                if (!achou) {
                    printf("Item '%s' nao encontrado na mochila.\n", nomeProcurado);
                }
            } else {
                printf("A mochila esta vazia!\n");
            }
             break;
                }
            }
}