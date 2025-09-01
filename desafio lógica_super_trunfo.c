#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_CARTAS 5

struct Carta {
    char nome[30];
    int forca;
    int velocidade;
    int inteligencia;
};

void mostrarCarta(struct Carta c) {
    printf("Nome: %s\n", c.nome);
    printf("Forca: %d\n", c.forca);
    printf("Velocidade: %d\n", c.velocidade);
    printf("Inteligencia: %d\n", c.inteligencia);
}

int main() {
    srand(time(NULL)); // Inicializa gerador de números aleatórios

    // Cartas disponíveis
    struct Carta cartas[NUM_CARTAS] = {
        {"Guerreiro",     80, 60, 50},
        {"Ninja",         60, 90, 70},
        {"Androide",      70, 60, 90},
        {"Mutante",       85, 55, 85},
        {"Mago Supremo",  50, 40, 100}
    };

    int escolhaJogador, atributo;
    
    printf("=== Super Trunfo - Desafio de Lógica ===\n");

    // Escolha do jogador
    printf("Escolha sua carta (0 a %d):\n", NUM_CARTAS - 1);
    for (int i = 0; i < NUM_CARTAS; i++) {
        printf("[%d] %s\n", i, cartas[i].nome);
    }

    printf(">> ");
    scanf("%d", &escolhaJogador);

    // Validação
    if (escolhaJogador < 0 || escolhaJogador >= NUM_CARTAS) {
        printf("Escolha inválida!\n");
        return 1;
    }

    struct Carta jogador = cartas[escolhaJogador];

    // Escolha de atributo
    printf("\nSua carta:\n");
    mostrarCarta(jogador);

    printf("\nEscolha um atributo para disputar:\n");
    printf("[1] Forca\n");
    printf("[2] Velocidade\n");
    printf("[3] Inteligencia\n");
    printf(">> ");
    scanf("%d", &atributo);

    // Sorteio da carta do computador
    int indiceCPU = rand() % NUM_CARTAS;
    struct Carta cpu = cartas[indiceCPU];

    printf("\nCarta do Computador:\n");
    mostrarCarta(cpu);

    // Comparação
    int valorJogador, valorCPU;

    switch (atributo) {
        case 1:
            valorJogador = jogador.forca;
            valorCPU = cpu.forca;
            break;
        case 2:
            valorJogador = jogador.velocidade;
            valorCPU = cpu.velocidade;
            break;
        case 3:
            valorJogador = jogador.inteligencia;
            valorCPU = cpu.inteligencia;
            break;
        default:
            printf("Atributo inválido!\n");
            return 1;
    }

    // Resultado
    printf("\nResultado da rodada:\n");
    if (valorJogador > valorCPU) {
        printf("Você venceu! (%d > %d)\n", valorJogador, valorCPU);
    } else if (valorJogador < valorCPU) {
        printf("Computador venceu! (%d < %d)\n", valorJogador, valorCPU);
    } else {
        printf("Empate! (%d = %d)\n", valorJogador, valorCPU);
    }

    return 0;
}
