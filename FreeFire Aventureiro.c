#include <stdio.h>
#include <string.h>

// Código da Ilha – Edição Free Fire
// Nível: Aventureiro

#define TAM 10

// Estrutura que representa um item da mochila
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Vetor que armazena os itens e controle do total
Item mochila[TAM];
int totalItens = 0;

// Inserir item na mochila
void inserirItem() {
    if (totalItens >= TAM) {
        printf("Mochila cheia.\n");
        return;
    }

    Item novo;
    getchar(); // Limpa o buffer do teclado

    printf("Nome: ");
    fgets(novo.nome, 30, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    printf("Tipo: ");
    fgets(novo.tipo, 20, stdin);
    novo.tipo[strcspn(novo.tipo, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[totalItens] = novo;
    totalItens++;
    printf("Item inserido com sucesso.\n");
}

// Remover item da mochila pelo nome
void removerItem() {
    if (totalItens == 0) {
        printf("A mochila está vazia.\n");
        return;
    }

    char nome[30];
    getchar();
    printf("Nome do item para remover: ");
    fgets(nome, 30, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    int encontrado = 0;
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            for (int j = i; j < totalItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            totalItens--;
            encontrado = 1;
            printf("Item removido com sucesso.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Item não encontrado na mochila.\n");
    }
}

// Listar todos os itens da mochila
void listarItens() {
    if (totalItens == 0) {
        printf("A mochila está vazia.\n");
        return;
    }

    printf("\nItens na mochila:\n");
    printf("-------------------------------\n");
    for (int i = 0; i < totalItens; i++) {
        printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
               mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
    printf("-------------------------------\n");
}

// Buscar item por nome (busca sequencial)
void buscarItem() {
    if (totalItens == 0) {
        printf("A mochila está vazia.\n");
        return;
    }

    char nome[30];
    getchar();
    printf("Nome do item para buscar: ");
    fgets(nome, 30, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    int encontrado = 0;

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            printf("\nItem encontrado:\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Item não encontrado na mochila.\n");
    }
}

// Menu principal
int main() {
    int opcao;

    do {
        printf("\n--- MENU MOCHILA ---\n");
        printf("1. Inserir item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item por nome\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: inserirItem(); break;
            case 2: removerItem(); break;
            case 3: listarItens(); break;
            case 4: buscarItem(); break;
            case 0: printf("Encerrando o programa.\n"); break;
            default: printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
