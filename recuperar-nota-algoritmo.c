#include <stdio.h>

int main(){

  int quantVendas = 0;
  float valor;
  float totalVendas = 0.0;
  float maiorVenda = 0.0;

  printf("------- PAINEL DE PRESTAÇÃO DE CONTAS -------\n");
  printf("Digite 0 para encerrar o programa.\n\n");
  
  printf("Digite o valor da venda: R$");
  scanf("%f", &valor);
  
  while(valor != 0){
      if(valor < 0){
          printf("\nValor inválido! Por favor, digite um valor válido.\n");
      }else{
          totalVendas += valor;
          quantVendas++;
          
          if(valor > maiorVenda){
              maiorVenda = valor;
          }
      }
      
      printf("Digite o valor da venda: R$");
      scanf("%f",&valor);
  }
    printf("------- RELATÓRIO DE VENDAS -------\n");
    
    if(quantVendas > 0){
        printf("Total vendido: %.2f\n", totalVendas);
        printf("Quantidade de vendas realizadas: %.d\n", quantVendas);
        printf("Maior valor de venda registrado: R$ %.2f\n", maiorVenda);
    }else{
        printf("Nenhuma venda foi registrada hoje.\n");
    }
    return 0;
}
