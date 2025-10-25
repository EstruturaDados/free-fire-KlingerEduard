#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Código da Ilha – Edição Free Fire
// Nível: Novato

// Struct para representar um item no inventário do jogador
typedef struct {
    char nome[30];    // Nome do item (ex.: "manga", "Bandagem")
    char tipo[20];    // Tipo do item (ex.: "arma", "municao", "cura")
    int quantidade;   // Quantidade do item
} Item;

// Protótipos das funções
void limparTela();
void exibirMenu();
void inserirItem(Item mochila[], int *numItens);
void removerItem(Item mochila[], int *numItens);
void listarItens(Item mochila[], int numItens);
void buscarItem(Item mochila[], int numItens);

int main() {
    Item mochila[10];       // Vetor para armazenar até 10 itens
    int numItens = 0;       // Contador de itens na mochila
    int opcao;

    // Loop principal do menu
    do {
        limparTela();
        exibirMenu();
        printf("Digite sua escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                inserirItem(mochila, &numItens);
                break;
            case 2:
                removerItem(mochila, &numItens);
                break;
            case 3:
                listarItens(mochila, numItens);
                break;
            case 4:
                buscarItem(mochila, numItens);
                break;
            case 0:
                printf("Saindo do programa. Boa fuga da ilha!\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
        if (opcao != 0) {
            printf("\nPressione Enter para continuar...");
            getchar();
        }
    } while (opcao != 0);

    return 0;
}

// Função para simular a limpeza da tela
void limparTela() {
    for (int i = 0; i < 30; i++) {
        printf("\n");
    }
}

// Função para exibir o menu principal
void exibirMenu() {
    printf("=== Sistema de Mochila - Código da Ilha ===\n");
    printf("1. Adicionar item\n");
    printf("2. Remover item\n");
    printf("3. Listar itens\n");
    printf("4. Buscar item por nome\n");
    printf("0. Sair\n");
}

// Função para inserir um novo item na mochila
void inserirItem(Item mochila[], int *numItens) {
    if (*numItens >= 10) {
        printf("Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novoItem;
    printf("Digite o nome do item (máx. 29 caracteres): ");
    fgets(novoItem.nome, 30, stdin);
    novoItem.nome[strcspn(novoItem.nome, "\n")] = '\0'; // Remove o '\n'

    printf("Digite o tipo do item (ex.: arma, municao, cura): ");
    fgets(novoItem.tipo, 20, stdin);
    novoItem.tipo[strcspn(novoItem.tipo, "\n")] = '\0'; // Remove o '\n'

    printf("Digite a quantidade: ");
    scanf("%d", &novoItem.quantidade);
    getchar(); // Limpa o buffer

    if (novoItem.quantidade < 0) {
        printf("Quantidade inválida! Deve ser maior ou igual a zero.\n");
        return;
    }

    mochila[*numItens] = novoItem;
    (*numItens)++;
    printf("Item '%s' adicionado com sucesso!\n", novoItem.nome);
    listarItens(mochila, *numItens); // Exibe a lista atualizada
}

// Função para remover um item da mochila pelo nome
void removerItem(Item mochila[], int *numItens) {
    if (*numItens == 0) {
        printf("Mochila vazia! Não há itens para remover.\n");
        return;
    }

    char nome[30];
    printf("Digite o nome do item a ser removido: ");
    fgets(nome, 30, stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Remove o '\n'

    int encontrado = 0;
    for (int i = 0; i < *numItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            encontrado = 1;
            // Desloca os itens para preencher a lacuna
            for (int j = i; j < *numItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            (*numItens)--;
            printf("Item '%s' removido com sucesso!\n", nome);
            break;
        }
    }

    if (!encontrado) {
        printf("Item '%s' não encontrado na mochila.\n", nome);
    } else {
        listarItens(mochila, *numItens); // Exibe a lista atualizada
    }
}

// Função para listar todos os itens da mochila
void listarItens(Item mochila[], int numItens) {
    if (numItens == 0) {
        printf("Mochila vazia!\n");
        return;
    }

    printf("\n=== Itens na Mochila ===\n");
    printf("----------------------------------------\n");
    printf("| %-20s | %-15s | %-8s |\n", "Nome", "Tipo", "Quantidade");
    printf("----------------------------------------\n");
    for (int i = 0; i < numItens; i++) {
        printf("| %-20s | %-15s | %-8d |\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
    printf("----------------------------------------\n");
}

// Função para buscar um item por nome (busca sequencial)
void buscarItem(Item mochila[], int numItens) {
    if (numItens == 0) {
        printf("Mochila vazia! Não há itens para buscar.\n");
        return;
    }

    char nome[30];
    printf("Digite o nome do item a ser buscado: ");
    fgets(nome, 30, stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Remove o '\n'

    int encontrado = 0;
    for (int i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            printf("\nItem encontrado:\n");
            printf("----------------------------------------\n");
            printf("| %-20s | %-15s | %-8s |\n", "Nome", "Tipo", "Quantidade");
            printf("----------------------------------------\n");
            printf("| %-20s | %-15s | %-8d |\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            printf("----------------------------------------\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Item '%s' não encontrado na mochila.\n", nome);
    }
}