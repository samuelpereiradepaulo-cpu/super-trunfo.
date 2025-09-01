#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 8

void mostrarTabuleiro(char tab[TAM][TAM]) {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
}

void limparTabuleiro(char tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tab[i][j] = '.';
}

void movimentosTorre(char tab[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < TAM; i++) {
        if (i != linha)
            tab[i][coluna] = '*';
        if (i != coluna)
            tab[linha][i] = '*';
    }
}

void movimentosBispo(char tab[TAM][TAM], int linha, int coluna) {
    for (int i = -TAM; i < TAM; i++) {
        int l1 = linha + i;
        int c1 = coluna + i;
        int l2 = linha + i;
        int c2 = coluna - i;
        if (l1 >= 0 && l1 < TAM && c1 >= 0 && c1 < TAM && !(l1 == linha && c1 == coluna))
            tab[l1][c1] = '*';
        if (l2 >= 0 && l2 < TAM && c2 >= 0 && c2 < TAM && !(l2 == linha && c2 == coluna))
            tab[l2][c2] = '*';
    }
}

void movimentosCavalo(char tab[TAM][TAM], int linha, int coluna) {
    int movimentos[8][2] = {
        {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
        {1, -2}, {1, 2}, {2, -1}, {2, 1}
    };

    for (int i = 0; i < 8; i++) {
        int l = linha + movimentos[i][0];
        int c = coluna + movimentos[i][1];
        if (l >= 0 && l < TAM && c >= 0 && c < TAM)
            tab[l][c] = '*';
    }
}

int main() {
    char tabuleiro[TAM][TAM];
    int linha, coluna;
    char colunaChar;
    int opcao;

    limparTabuleiro(tabuleiro);

    printf("=== Movimentação de Peças do Xadrez ===\n");
    printf("Escolha uma peça:\n");
    printf("[1] Torre\n");
    printf("[2] Bispo\n");
    printf("[3] Cavalo\n");
    printf(">> ");
    scanf("%d", &opcao);

    printf("\nInforme a posição da peça (ex: E4): ");
    scanf(" %c%d", &colunaChar, &linha);

    colunaChar = toupper(colunaChar);
    coluna = colunaChar - 'A';
    linha -= 1;

    if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM) {
        printf("Posição inválida!\n");
        return 1;
    }

    tabuleiro[linha][coluna] = 'P'; // Marca a peça na posição escolhida

    switch (opcao) {
        case 1:
            movimentosTorre(tabuleiro, linha, coluna);
            break;
        case 2:
            movimentosBispo(tabuleiro, linha, coluna);
            break;
        case 3:
            movimentosCavalo(tabuleiro, linha, coluna);
            break;
        default:
            printf("Opção inválida.\n");
            return 1;
    }

    printf("\nTabuleiro com movimentos possíveis (*):\n");
    mostrarTabuleiro(tabuleiro);

    return 0;
}
