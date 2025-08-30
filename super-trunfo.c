#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[30];
    int poder;
    int velocidade;
    int inteligencia;
} Carta;

void mostrarCarta(Carta c) {
    printf("Carta: %s\n", c.nome);
    printf("Poder: %d\n", c.poder);
    printf("Velocidade: %d\n", c.velocidade);
    printf("Inteligência: %d\n", c.inteligencia);
}

int main() {
    Carta carta1 = {"Super Homem", 90, 80, 85};
    Carta carta2 = {"Batman", 70, 60, 95};

    int atributo;

    printf("Escolha o atributo para comparar:\n");
    printf("1 - Poder\n2 - Velocidade\n3 - Inteligência\n");
    scanf("%d", &atributo);

    printf("\nCarta 1:\n");
    mostrarCarta(carta1);
    printf("\nCarta 2:\n");
    mostrarCarta(carta2);

    int valor1, valor2;

    switch(atributo) {
        case 1:
            valor1 = carta1.poder;
            valor2 = carta2.poder;
            break;
        case 2:
            valor1 = carta1.velocidade;
            valor2 = carta2.velocidade;
            break;
        case 3:
            valor1 = carta1.inteligencia;
            valor2 = carta2.inteligencia;
            break;
        default:
            printf("Atributo inválido!\n");
            return 1;
    }

    if (valor1 > valor2) {
        printf("\nCarta 1 vence!\n");
    } else if (valor2 > valor1) {
        printf("\nCarta 2 vence!\n");
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}
