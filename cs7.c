#include <stdio.h>

int main() {
  int idade, dep;
  float renda;

printf("Informe sua idade: ");
scanf("%d", &idade);
printf("Informe sua renda: ");
scanf("%f", &renda);
printf("Informe o número de dependentes: ");
scanf("%d", &dep);


  if(idade >= 18 && idade < 65){
    if(renda < 3000.0){
      if(dep > 2){
        printf("Você atende a todos os critérios.");
      }else{
        printf("Você não atende ao critério dependentes.");
      }
    }else{
      printf("Você não atende ao critério renda.");
    }
  }else{
    printf("Você não atende ao critério idade.\n");
  }

  return 0;
}