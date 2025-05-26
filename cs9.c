#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int escolhaJogador, escolhaComputador;

    srand(time(0));

    printf("\n---- JOKEMPÔ EM C ----\n");
    printf("Escolha uma Opção: \n1.Pedra \n2.Papel \n3.Tesoura\n");
    printf("ESCOLHA: ");
    scanf("%d", &escolhaJogador);

    escolhaComputador = rand() %3 + 1;

    switch (escolhaJogador){
    case 1:
        printf("Jogador: Pedra x ");
        break;
    case 2:
        printf("Jogador: Papel x ");
        break;
    case 3:
        printf("Jogador: Tesoura x ");
        break;
    default:
        printf("*OPÇÃO INVÁLIDA*\n");
        break;
    }
    switch (escolhaComputador){
    case 1:
        printf("Computador: Pedra \n");
        break;
    case 2:
        printf("Computador: Papel \n");
        break;
    case 3:
        printf("Computador: Tesoura \n");
        break;
        }

    if(escolhaJogador == escolhaComputador){
        printf("---- EMPATE ----\n");
    }else if((escolhaJogador == 1) && (escolhaComputador == 3) || (escolhaJogador == 2) && (escolhaComputador == 1) || (escolhaJogador == 3) && (escolhaComputador == 2)){
        printf("---- VOCÊ GANHOU ----\n");
    }else{
        printf("---- VOCÊ PERDEU ----\n");
    }

    return 0;
}