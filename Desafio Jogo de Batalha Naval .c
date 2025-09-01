#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5
#define NAVIOS 3

void inicializarTabuleiro(char tab[TAM][TAM], char simbolo) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tab[i][j] = simbolo;
}

void posicionarNavios(int navios[TAM][TAM]) {
    int naviosRestantes = NAVIOS;
    while (naviosRestantes > 0) {
        int linha = rand() % TAM;
        int coluna = rand() % TAM;

        if (navios[linha][coluna] == 0) {
            navios[linha][coluna] = 1;
            naviosRestantes--;
        }
    }
}

void exibirTabuleiro(char tab[TAM][TAM]) {
    printf("  A B C D E\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
}

int converterColuna(char letra) {
    return letra - 'A';
}

int main() {
    char tabuleiro[TAM][TAM];
    int navios[TAM][TAM] = {0};
    int acertos = 0;
    int tentativas = 0;
    int linha, coluna;
    char colunaChar;

    srand(time(NULL));

    inicializarTabuleiro(tabuleiro, '~');
    posicionarNavios(navios);

    printf("=== BATALHA NAVAL ===\n");
    printf("Objetivo: Acertar os %d navios escondidos no mar.\n", NAVIOS);

    while (acertos < NAVIOS) {
        exibirTabuleiro(tabuleiro);

        printf("\nDigite a posição (ex: B3): ");
        scanf(" %c%d", &colunaChar, &linha);

        colunaChar = toupper(colunaChar);
        coluna = converterColuna(colunaChar);
        linha -= 1;

        if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM) {
            printf("Posição inválida!\n");
            continue;
        }

        if (tabuleiro[linha][coluna] == 'X' || tabuleiro[linha][coluna] == 'O') {
            printf("Você já tentou essa posição!\n");
            continue;
        }

        tentativas++;

        if (navios[linha][coluna] == 1) {
            printf("💥 Acertou um navio!\n");
            tabuleiro[linha][coluna] = 'X';
            acertos++;
        } else {
            printf("🌊 Água!\n");
            tabuleiro[linha][coluna] = 'O';
        }
    }

    printf("\n🎉 Parabéns! Você afundou todos os navios em %d tentativas.\n", tentativas);
    exibirTabuleiro(tabuleiro);

    return 0;
}
