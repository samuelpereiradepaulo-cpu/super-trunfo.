#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_TABULEIRO 10
#define NUM_NAVIOS 3

// Função para inicializar o tabuleiro
void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = '~'; // ' ~ ' representa a água
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int esconderNavios) {
    printf("  ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (esconderNavios && tabuleiro[i][j] == 'N') {
                printf("~ "); // Esconde os navios do adversário
            } else {
                printf("%c ", tabuleiro[i][j]);
            }
        }
        printf("\n");
    }
}

// Função para posicionar os navios aleatoriamente
void posicionarNavios(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int numNavios) {
    int i = 0;
    while (i < numNavios) {
        int linha = rand() % TAMANHO_TABULEIRO;
        int coluna = rand() % TAMANHO_TABULEIRO;

        if (tabuleiro[linha][coluna] == '~') {
            tabuleiro[linha][coluna] = 'N'; // ' N ' representa um navio
            i++;
        }
    }
}

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    char tabuleiroJogador[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    char tabuleiroComputador[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    int naviosJogador = NUM_NAVIOS;
    int naviosComputador = NUM_NAVIOS;

    // Inicializa e posiciona os navios
    inicializarTabuleiro(tabuleiroJogador);
    posicionarNavios(tabuleiroJogador, naviosJogador);

    inicializarTabuleiro(tabuleiroComputador);
    posicionarNavios(tabuleiroComputador, naviosComputador);
    
    printf("Bem-vindo ao Batalha Naval!\n");
    printf("Voce e o computador tem 3 navios cada.\n");
    printf("Tente afundar os navios do seu adversario!\n\n");

    while (naviosJogador > 0 && naviosComputador > 0) {
        // Turno do Jogador
        printf("\n--- Seu Turno ---\n");
        exibirTabuleiro(tabuleiroComputador, 1); // Exibe o tabuleiro do computador (com navios escondidos)
        
        int linha, coluna;
        printf("\nDigite a linha e a coluna para atacar (0-9): ");
        scanf("%d %d", &linha, &coluna);

        if (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO) {
            printf("Coordenadas invalidas! Tente novamente.\n");
            continue;
        }

        if (tabuleiroComputador[linha][coluna] == 'N') {
            printf("PARABENS! Voce acertou um navio!\n");
            tabuleiroComputador[linha][coluna] = 'X'; // ' X ' para acerto
            naviosComputador--;
        } else if (tabuleiroComputador[linha][coluna] == '~') {
            printf("Voce acertou a agua.\n");
            tabuleiroComputador[linha][coluna] = 'O'; // ' O ' para erro
        } else {
            printf("Voce ja atirou aqui. Tente outro local.\n");
        }

        if (naviosComputador == 0) {
            printf("\n--- FIM DE JOGO ---\n");
            printf("Parabens! Voce afundou todos os navios do computador e venceu!\n");
            break;
        }

        // Turno do Computador
        printf("\n--- Turno do Computador ---\n");
        do {
            linha = rand() % TAMANHO_TABULEIRO;
            coluna = rand() % TAMANHO_TABULEIRO;
        } while (tabuleiroJogador[linha][coluna] == 'X' || tabuleiroJogador[linha][coluna] == 'O');
        
        printf("O computador atacou em %d %d.\n", linha, coluna);
        
        if (tabuleiroJogador[linha][coluna] == 'N') {
            printf("Seu navio foi atingido!\n");
            tabuleiroJogador[linha][coluna] = 'X';
            naviosJogador--;
        } else {
            printf("O computador errou!\n");
            tabuleiroJogador[linha][coluna] = 'O';
        }

        if (naviosJogador == 0) {
            printf("\n--- FIM DE JOGO ---\n");
            printf("Que pena! Todos os seus navios foram afundados. O computador venceu!\n");
            break;
        }
        
        printf("\n--- Seu Tabuleiro Atualizado ---\n");
        exibirTabuleiro(tabuleiroJogador, 0); // Exibe seu próprio tabuleiro
    }
    
    return 0;
}
