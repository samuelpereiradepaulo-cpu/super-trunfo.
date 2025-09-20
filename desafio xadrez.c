#include <stdio.h>

#define TAMANHO_TABULEIRO 8

// Função para exibir o tabuleiro
void exibirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n  a b c d e f g h\n");
    printf("------------------\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d|", TAMANHO_TABULEIRO - i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se o movimento do cavalo e valido
int movimentoCavaloValido(int linhaInicial, int colunaInicial, int linhaFinal, int colunaFinal) {
    int deltaLinha = abs(linhaFinal - linhaInicial);
    int deltaColuna = abs(colunaFinal - colunaInicial);

    // Um movimento de cavalo valido e sempre 2x1 ou 1x2 em qualquer direcao
    return (deltaLinha == 2 && deltaColuna == 1) || (deltaLinha == 1 && deltaColuna == 2);
}

int main() {
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro vazio
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = '.';
        }
    }

    // Posiciona um cavalo para o exemplo
    int linhaCavalo = 4;
    int colunaCavalo = 3;
    tabuleiro[linhaCavalo][colunaCavalo] = 'C';

    exibirTabuleiro(tabuleiro);

    int linhaDestino, colunaDestino;
    printf("\nOnde voce quer mover o cavalo (linha coluna)? (Ex: 3 4)\n");
    printf("Digite -1 para sair.\n");

    while (1) {
        printf("Sua jogada: ");
        scanf("%d %d", &linhaDestino, &colunaDestino);

        if (linhaDestino == -1) {
            printf("Saindo do programa.\n");
            break;
        }

        // Converte as coordenadas do usuario (1-8) para indices da matriz (0-7)
        linhaDestino = TAMANHO_TABULEIRO - linhaDestino;
        colunaDestino--; // A coluna 'a' e 0, 'b' e 1, etc.

        if (linhaDestino < 0 || linhaDestino >= TAMANHO_TABULEIRO || colunaDestino < 0 || colunaDestino >= TAMANHO_TABULEIRO) {
            printf("Coordenadas invalidas. Tente novamente.\n");
            continue;
        }
        
        if (movimentoCavaloValido(linhaCavalo, colunaCavalo, linhaDestino, colunaDestino)) {
            printf("Movimento do cavalo e valido!\n");
        } else {
            printf("Movimento do cavalo e invalido!\n");
        }
    }

    return 0;
}
