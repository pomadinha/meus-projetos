#include <stdio.h>

int main(){

    // MOVIMENTO DA TORRE (usando for)
    printf("\n          Movimentos da Torre\n");
    for(int torre = 1; torre < 6; torre++) {
        printf("Movimento da torre: %d casa(s) para direita.\n", torre);
    }

    // MOVIMENTO DO BISPO (usando while)
    printf("\n          Movimentos do Bispo\n");
    int bispo = 1; //declarando a variável bispo
    while(bispo <= 5) {
        printf("Movimento do bispo: %d casa(s) para cima, direita.\n", bispo);
        bispo++;
    }

    // MOVIMENTO DA RAINHA (usando do-while)
    printf("\n          Movimentos da Rainha\n");
    int rainha = 1; //declarando a variável rainha
    do {
        printf("Movimento da rainha: %d casa(s) para esquerda.\n", rainha);
        rainha++;
    } while(rainha <= 8);

    return 0;
}