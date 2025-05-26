#include <stdio.h>

int main(){
    int opcao;
    float saldo = 3000.0;

    printf("Escolha uma opção: \n");
    printf("1. Verificar saldo. \n");
    printf("2. Fazer depósito. \n");
    printf("3. Fazer saque. \n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
    printf("Seu saldo é de: %.2f\n", saldo);
        break;
    case 2:
    printf("Digite o banco que deseja depositar: \n");
    printf("Digite a agência: \n");
    printf("Digite a conta: \n");
        break;
    case 3:
    printf("digite um valor a sacar: \n");
        break;
    default:
    printf("Opção inválida.\n");
        break;
    }

    return 0;
}