#include <stdio.h>
int main(){

    int numero; 

    do{
        printf("Digite um número par para sair do programa: ");
        scanf("%d", &numero);

        if(numero %2 == 0){
            printf("%d é par.\n", numero);
        }else{
            printf("%d é ímpar.\n", numero);
        }

    }while(numero % 2 != 0);
    printf("Saindo do programa...\n");

    return 0;
}