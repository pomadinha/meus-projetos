#include <stdio.h>

int main() {
    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; 
    int matriz[10][10] = {{0}}; // Inicia toda a matriz com 0 (representando o mar)

    // Imprime o tabuleiro
    printf("- TABULEIRO BATALHA NAVAL -\n");
    printf("   ");
    for(int a = 0; a < 10; a++){
        printf("%c ", letras[a]); 
    }
    printf("\n");

    // Posição do navio na horizontal
    for(int y = 2; y < 5; y++){
        matriz[1][y] = 3;
    }
    
    // Posição do navio na vertical
    for(int x = 6; x < 9; x++){
        matriz[x][7] = 3;
    }

    // Tabuleiro com numeração
    for(int x = 0; x < 10; x++){
        printf("%2d ", x + 1); 
        for(int y = 0; y < 10; y++){
            printf("%d ", matriz[x][y]);
        }
        printf("\n");
    }

    return 0;
}