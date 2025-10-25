#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Código da Ilha – Edição Free Fire
// Nível: Mestre
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.

#define MAX 20

// Estrutura que representa um componente da torre
typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade; // valor de 1 a 10
} Componente;

// Protótipos das funções
void cadastrarComponentes(Componente componentes[], int *n);
void mostrarComponentes(Componente componentes[], int n);
void bubbleSortNome(Componente componentes[], int n, int *comparacoes);
void insertionSortTipo(Componente componentes[], int n, int *comparacoes);
void selectionSortPrioridade(Componente componentes[], int n, int *comparacoes);
int buscaBinariaPorNome(Componente componentes[], int n, char nomeBuscado[], int *comparacoes);

int main() {
    Componente componentes[MAX];
    int n = 0;
    int opcao;
    int comparacoes;
    clock_t inicio, fim;
    double tempo;

    do {
        printf("\n=== MENU - NÍVEL MESTRE: ORDENACAO E BUSCA BINARIA ===\n");
        printf("1. Cadastrar componentes\n");
        printf("2. Listar componentes\n");
        printf("3. Ordenar por nome (Bubble Sort)\n");
        printf("4. Ordenar por tipo (Insertion Sort)\n");
        printf("5. Ordenar por prioridade (Selection Sort)\n");
        printf("6. Buscar componente por nome (Busca Binária)\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                cadastrarComponentes(componentes, &n);
                break;

            case 2:
                mostrarComponentes(componentes, n);
                break;

            case 3:
                comparacoes = 0;
                inicio = clock();
                bubbleSortNome(componentes, n, &comparacoes);
                fim = clock();
                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("Ordenação por nome concluída.\n");
                printf("Comparações: %d | Tempo: %.6f segundos\n", comparacoes, tempo);
                break;

            case 4:
                comparacoes = 0;
                inicio = clock();
                insertionSortTipo(componentes, n, &comparacoes);
                fim = clock();
                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("Ordenação por tipo concluída.\n");
                printf("Comparações: %d | Tempo: %.6f segundos\n", comparacoes, tempo);
                break;

            case 5:
                comparacoes = 0;
                inicio = clock();
                selectionSortPrioridade(componentes, n, &comparacoes);
                fim = clock();
                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("Ordenação por prioridade concluída.\n");
                printf("Comparações: %d | Tempo: %.6f segundos\n", comparacoes, tempo);
                break;

            case 6: {
                char nomeBuscado[30];
                int resultado;
                comparacoes = 0;

                if (n == 0) {
                    printf("Nenhum componente cadastrado.\n");
                    break;
                }

                printf("Digite o nome do componente para buscar: ");
                fgets(nomeBuscado, 30, stdin);
                nomeBuscado[strcspn(nomeBuscado, "\n")] = '\0';

                resultado = buscaBinariaPorNome(componentes, n, nomeBuscado, &comparacoes);

                if (resultado != -1) {
                    printf("\nComponente encontrado:\n");
                    printf("Nome: %s\n", componentes[resultado].nome);
                    printf("Tipo: %s\n", componentes[resultado].tipo);
                    printf("Prioridade: %d\n", componentes[resultado].prioridade);
                } else {
                    printf("Componente não encontrado.\n");
                }
                printf("Comparações na busca: %d\n", comparacoes);
                break;
            }

            case 0:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}

// Cadastro de até 20 componentes
void cadastrarComponentes(Componente componentes[], int *n) {
    if (*n >= MAX) {
        printf("Limite de componentes atingido.\n");
        return;
    }

    Componente novo;
    printf("Nome do componente: ");
    fgets(novo.nome, 30, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    printf("Tipo do componente: ");
    fgets(novo.tipo, 20, stdin);
    novo.tipo[strcspn(novo.tipo, "\n")] = '\0';

    printf("Prioridade (1 a 10): ");
    scanf("%d", &novo.prioridade);
    getchar();

    componentes[*n] = novo;
    (*n)++;
    printf("Componente cadastrado com sucesso.\n");
}

// Exibição dos componentes
void mostrarComponentes(Componente componentes[], int n) {
    if (n == 0) {
        printf("Nenhum componente cadastrado.\n");
        return;
    }

    printf("\n--- LISTA DE COMPONENTES ---\n");
    printf("%-25s %-20s %-10s\n", "Nome", "Tipo", "Prioridade");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-25s %-20s %-10d\n", componentes[i].nome, componentes[i].tipo, componentes[i].prioridade);
    }
}

// Bubble Sort - Ordena por nome
void bubbleSortNome(Componente componentes[], int n, int *comparacoes) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comparacoes)++;
            if (strcmp(componentes[j].nome, componentes[j + 1].nome) > 0) {
                Componente temp = componentes[j];
                componentes[j] = componentes[j + 1];
                componentes[j + 1] = temp;
            }
        }
    }
}

// Insertion Sort - Ordena por tipo
void insertionSortTipo(Componente componentes[], int n, int *comparacoes) {
    for (int i = 1; i < n; i++) {
        Componente chave = componentes[i];
        int j = i - 1;

        while (j >= 0 && strcmp(componentes[j].tipo, chave.tipo) > 0) {
            (*comparacoes)++;
            componentes[j + 1] = componentes[j];
            j--;
        }
        componentes[j + 1] = chave;
    }
}

// Selection Sort - Ordena por prioridade
void selectionSortPrioridade(Componente componentes[], int n, int *comparacoes) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            (*comparacoes)++;
            if (componentes[j].prioridade < componentes[min].prioridade) {
                min = j;
            }
        }
        if (min != i) {
            Componente temp = componentes[i];
            componentes[i] = componentes[min];
            componentes[min] = temp;
        }
    }
}

// Busca Binária - busca por nome (requer vetor ordenado por nome)
int buscaBinariaPorNome(Componente componentes[], int n, char nomeBuscado[], int *comparacoes) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        (*comparacoes)++;

        int cmp = strcmp(componentes[meio].nome, nomeBuscado);

        if (cmp == 0) {
            return meio;
        } else if (cmp < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}
