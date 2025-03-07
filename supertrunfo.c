#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura da Carta sem typedef
struct Carta {
    char nomeCidade[50];
    int populacao;
    float densidadePopulacional;
    float areaKm2;
    float pib;
    float pibPerCapita;
    int pontosTuristicos;
    float superPoder;
};

// Função para calcular o Super Poder
float calcularSuperPoder(struct Carta carta) {
    return carta.populacao + carta.areaKm2 + carta.pib + carta.pibPerCapita +
           (1.0 / carta.densidadePopulacional) + carta.pontosTuristicos;
}

// Função para obter o valor de um atributo
float obterValor(struct Carta carta, int atributo) {
    if (atributo == 1) return carta.populacao;
    if (atributo == 2) return carta.densidadePopulacional;
    if (atributo == 3) return carta.areaKm2;
    if (atributo == 4) return carta.pib;
    if (atributo == 5) return carta.pibPerCapita;
    if (atributo == 6) return carta.pontosTuristicos;
    return carta.superPoder; // Caso seja Super Poder
}

int main() {
    // Inicialização do gerador de números aleatórios
    srand(time(NULL));

    // Definição das cartas sem typedef
    struct Carta carta1 = {"Rio de Janeiro", 6748000, 5265.82, 1200.27, 361.03, 53718.5, 15, 0};
    struct Carta carta2 = {"São Paulo", 12330000, 7389.37, 1521.11, 699.28, 56692.6, 20, 0};

    // Cálculo dos Super Poderes
    carta1.superPoder = calcularSuperPoder(carta1);
    carta2.superPoder = calcularSuperPoder(carta2);

    // Menu de seleção de atributos
    int atributo1, atributo2;
    printf("Selecione os atributos para comparação:\n");
    printf("1 - População\n2 - Densidade Populacional\n3 - Área em km²\n4 - PIB\n");
    printf("5 - PIB Per Capita\n6 - Pontos Turísticos\n7 - Super Poder\n");
    
    // Escolha do primeiro atributo
    printf("Escolha o primeiro atributo: ");
    scanf("%d", &atributo1);

    // Escolha do segundo atributo
    printf("Escolha o segundo atributo: ");
    scanf("%d", &atributo2);

    // Obtenção dos valores selecionados
    float somaC1 = obterValor(carta1, atributo1) + obterValor(carta1, atributo2);
    float somaC2 = obterValor(carta2, atributo1) + obterValor(carta2, atributo2);

    // Comparação e exibição dos resultados
    printf("\nResultado:\n");
    if (somaC1 > somaC2) {
        printf("Vencedor: %s\n", carta1.nomeCidade);
    } else if (somaC1 < somaC2) {
        printf("Vencedor: %s\n", carta2.nomeCidade);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
