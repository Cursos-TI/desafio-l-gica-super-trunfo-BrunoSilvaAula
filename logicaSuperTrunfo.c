#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
struct Carta {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

void exibirMenuAtributos() {
    printf("Escolha um atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área (km²)\n");
    printf("3 - PIB (bilhões)\n");
    printf("4 - Pontos Turísticos\n");
}

int escolherAtributo(int excluido) {
    int escolha;
    do {
        exibirMenuAtributos();
        scanf("%d", &escolha);
        if (escolha == excluido) {
            printf("Você já escolheu esse atributo! Escolha outro.\n");
        }
    } while (escolha < 1 || escolha > 4 || escolha == excluido);
    return escolha;
}

float obterValorAtributo(struct Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
    }
    return 0;
}

void compararCartas(struct Carta c1, struct Carta c2) {
    int atributo1 = escolherAtributo(0);
    int atributo2 = escolherAtributo(atributo1);
    
    float valor1_c1 = obterValorAtributo(c1, atributo1);
    float valor1_c2 = obterValorAtributo(c2, atributo1);
    float valor2_c1 = obterValorAtributo(c1, atributo2);
    float valor2_c2 = obterValorAtributo(c2, atributo2);
    
    int pontosC1 = (valor1_c1 > valor1_c2) + (valor2_c1 > valor2_c2);
    int pontosC2 = (valor1_c1 < valor1_c2) + (valor2_c1 < valor2_c2);
    
    float somaC1 = valor1_c1 + valor2_c1;
    float somaC2 = valor1_c2 + valor2_c2;
    
    printf("\nResultado da Comparação:\n");
    printf("%s - Atributo %d: %.2f | Atributo %d: %.2f | Soma: %.2f\n", c1.nomeCidade, atributo1, valor1_c1, atributo2, valor2_c1, somaC1);
    printf("%s - Atributo %d: %.2f | Atributo %d: %.2f | Soma: %.2f\n", c2.nomeCidade, atributo1, valor1_c2, atributo2, valor2_c2, somaC2);
    
    if (somaC1 > somaC2) {
        printf("Vencedor: %s!\n", c1.nomeCidade);
    } else if (somaC2 > somaC1) {
        printf("Vencedor: %s!\n", c2.nomeCidade);
    } else {
        printf("Empate!\n");
    }
}

int main() {
    struct Carta carta1, carta2;
    
    printf("Cadastro da primeira carta:\n");
    printf("Digite o nome da cidade: ");
    scanf(" %s", carta1.nomeCidade);
    printf("Digite a população: ");
    scanf(" %d", &carta1.populacao);
    printf("Digite a área em km²: ");
    scanf(" %f", &carta1.area);
    printf("Digite o PIB em bilhões: ");
    scanf(" %f", &carta1.pib);
    printf("Digite o número de pontos turísticos: ");
    scanf(" %d", &carta1.pontosTuristicos);
    
    printf("\nCadastro da segunda carta:\n");
    printf("Digite o nome da cidade: ");
    scanf(" %s", carta2.nomeCidade);
    printf("Digite a população: ");
    scanf(" %d", &carta2.populacao);
    printf("Digite a área em km²: ");
    scanf(" %f", &carta2.area);
    printf("Digite o PIB em bilhões: ");
    scanf(" %f", &carta2.pib);
    printf("Digite o número de pontos turísticos: ");
    scanf(" %d", &carta2.pontosTuristicos);
    
    compararCartas(carta1, carta2);
    return 0;
}
