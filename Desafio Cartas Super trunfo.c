#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Definição da estrutura de uma carta
typedef struct {
    char nome[50];
    int ataque;
    int defesa;
    int velocidade;
    int forca;
} Carta;

// Função para criar o baralho
void criarBaralho(Carta baralho[], int tamanho) {
    strcpy(baralho[0].nome, "Dragao Flamejante");
    baralho[0].ataque = 90;
    baralho[0].defesa = 70;
    baralho[0].velocidade = 50;
    baralho[0].forca = 85;

    strcpy(baralho[1].nome, "Grifo Veloz");
    baralho[1].ataque = 75;
    baralho[1].defesa = 60;
    baralho[1].velocidade = 95;
    baralho[1].forca = 70;

    strcpy(baralho[2].nome, "Golem de Rocha");
    baralho[2].ataque = 80;
    baralho[2].defesa = 95;
    baralho[2].velocidade = 30;
    baralho[2].forca = 90;
    
    strcpy(baralho[3].nome, "Elfo Arqueiro");
    baralho[3].ataque = 85;
    baralho[3].defesa = 55;
    baralho[3].velocidade = 80;
    baralho[3].forca = 65;

    strcpy(baralho[4].nome, "Ogro Bruto");
    baralho[4].ataque = 95;
    baralho[4].defesa = 80;
    baralho[4].velocidade = 20;
    baralho[4].forca = 95;
    
    // Adicione mais cartas aqui
}

// Função para exibir as cartas de um jogador
void exibirCartas(Carta carta1, Carta carta2) {
    printf("\n--- Sua Carta ---\n");
    printf("Nome: %s\n", carta1.nome);
    printf("1) Ataque: %d\n", carta1.ataque);
    printf("2) Defesa: %d\n", carta1.defesa);
    printf("3) Velocidade: %d\n", carta1.velocidade);
    printf("4) Forca: %d\n", carta1.forca);
    
    printf("\n--- Carta do Adversario ---\n");
    printf("Nome: %s\n", carta2.nome);
    printf("1) Ataque: ??\n");
    printf("2) Defesa: ??\n");
    printf("3) Velocidade: ??\n");
    printf("4) Forca: ??\n");
}

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    
    Carta baralho[5]; // Exemplo com 5 cartas
    criarBaralho(baralho, 5);
    
    int escolha;
    int indiceJogador, indiceAdversario;
    
    printf("Bem-vindo ao Super Trunfo!\n");
    printf("O jogo comecara.\n");
    
    // Distribui as cartas aleatoriamente
    indiceJogador = rand() % 5;
    do {
        indiceAdversario = rand() % 5;
    } while (indiceAdversario == indiceJogador);
    
    exibirCartas(baralho[indiceJogador], baralho[indiceAdversario]);
    
    printf("\nEscolha uma caracteristica para jogar (1-4): ");
    scanf("%d", &escolha);
    
    int valorJogador, valorAdversario;
    
    // Obtem o valor da característica escolhida
    switch (escolha) {
        case 1:
            valorJogador = baralho[indiceJogador].ataque;
            valorAdversario = baralho[indiceAdversario].ataque;
            break;
        case 2:
            valorJogador = baralho[indiceJogador].defesa;
            valorAdversario = baralho[indiceAdversario].defesa;
            break;
        case 3:
            valorJogador = baralho[indiceJogador].velocidade;
            valorAdversario = baralho[indiceAdversario].velocidade;
            break;
        case 4:
            valorJogador = baralho[indiceJogador].forca;
            valorAdversario = baralho[indiceAdversario].forca;
            break;
        default:
            printf("Escolha invalida!\n");
            return 1;
    }
    
    printf("\n--- Resultado ---\n");
    printf("Seu valor: %d\n", valorJogador);
    printf("Valor do adversario: %d\n", valorAdversario);
    
    // Compara os valores
    if (valorJogador > valorAdversario) {
        printf("\nParabens, voce venceu!\n");
    } else if (valorJogador < valorAdversario) {
        printf("\nQue pena, voce perdeu!\n");
    } else {
        printf("\nEmpate!\n");
    }
    
    return 0;
}****
