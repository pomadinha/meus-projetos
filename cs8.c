#include <stdio.h>
int main(){

   int idade;

   printf("Informe sua idade: ");
   scanf("%d", &idade);

    if(idade > 60){
        printf("Você é um idoso");
    }else if(idade <= 59 && idade > 18){
        printf("Você é adulto");
    }else if (idade < 18 && idade >=13){
        printf("Você é um adolescente");
    }else{
        printf("Você é uma criança");
    }
return 0;
}