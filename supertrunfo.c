#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura representando uma carta de Super Trunfo
typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
} Carta;

// Função para exibir o menu de opções
void exibirMenu() {
    printf("\n--- Menu de Comparação ---\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    printf("Escolha um atributo para comparar (1-5): ");
}

// Obter escolha do usuário com validação
int obterEscolha() {
    int escolha;
    scanf("%d", &escolha);

    while (escolha < 1 || escolha > 5) {
        printf("Opção inválida! Escolha novamente (1-5): ");
        scanf("%d", &escolha);
    }
    return escolha;
}

// Função para realizar a comparação entre os valores de um atributo
void realizarComparacao(Carta carta1, Carta carta2, int escolha) {
    printf("\n--- Comparação ---\n");
    printf("País 1: %s\n", carta1.nome);
    printf("País 2: %s\n", carta2.nome);

    switch (escolha) {
        case 1: // Comparação de População
            printf("Atributo: População\n");
            printf("%d vs %d\n", carta1.populacao, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Vencedor: %s\n", carta1.nome);
            } else if (carta1.populacao < carta2.populacao) {
                printf("Vencedor: %s\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        case 2: // Comparação de Área
            printf("Atributo: Área\n");
            printf("%.2f vs %.2f\n", carta1.area, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Vencedor: %s\n", carta1.nome);
            } else if (carta1.area < carta2.area) {
                printf("Vencedor: %s\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        case 3: // Comparação de PIB
            printf("Atributo: PIB\n");
            printf("%.2f vs %.2f\n", carta1.pib, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Vencedor: %s\n", carta1.nome);
            } else if (carta1.pib < carta2.pib) {
                printf("Vencedor: %s\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        case 4: // Comparação de Pontos Turísticos
            printf("Atributo: Pontos Turísticos\n");
            printf("%d vs %d\n", carta1.pontosTuristicos, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Vencedor: %s\n", carta1.nome);
            } else if (carta1.pontosTuristicos < carta2.pontosTuristicos) {
                printf("Vencedor: %s\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        case 5: // Comparação de Densidade Demográfica
            printf("Atributo: Densidade Demográfica\n");
            printf("%.2f vs %.2f\n", carta1.densidadeDemografica, carta2.densidadeDemografica);
            if (carta1.densidadeDemografica < carta2.densidadeDemografica) { // Regra invertida
                printf("Vencedor: %s\n", carta1.nome);
            } else if (carta1.densidadeDemografica > carta2.densidadeDemografica) {
                printf("Vencedor: %s\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        default:
            printf("Erro inesperado!\n");
            break;
    }
}

int main() {
    // Inicializa as cartas com valores
    Carta carta1 = {"Brasil", 213000000, 8516000.0, 1.44, 20, 25.0};
    Carta carta2 = {"Argentina", 45100000, 2780000.0, 0.64, 15, 16.2};

    printf("--- Bem-vindo ao Super Trunfo! ---\n");

    // Exibe o menu e realiza a comparação
    exibirMenu();
    int escolha = obterEscolha();
    realizarComparacao(carta1, carta2, escolha);

    return 0;
}
