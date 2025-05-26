#include <stdio.h>

int main(){
//char pois é uma cadeia de caracteres 
char produtoA[15] = "Produto A"; 
char produtoB[15] = "Produto B";

//unsigned pois não será utilizado valores negativos (aumenta precisão e quantidade de números)
unsigned int estoqueA = 2000; 
unsigned int estoqueB = 2000;

//float porque o número é pequeno (em grandes casos é usado double)
float valorA = 5.50; 
float valorB = 20.40;

unsigned int estoqueMinimoA = 500;
unsigned int estoqueMinimoB = 2500;

//os valores totais têm de ser precisos
double valorTotalA; 
double valorTotalB;

int resultadoA, resultadoB;

// exibir as informações dos produtos
printf("O %s tem estoque %u e o valor unitário é R$%.2f\n", produtoA, estoqueA, valorA);
printf("O %s tem estoque %u e o valor unitário é R$%.2f\n", produtoB, estoqueB, valorB);

// comparações com valores mínimos de estoque
resultadoA = estoqueA > estoqueMinimoA;
resultadoB = estoqueB > estoqueMinimoB;

printf("O %s tem estoque mínimo %d\n", produtoA, resultadoA);
printf("O %s tem estoque mínimo %d\n", produtoB, resultadoB);

// comparações com valores totais dos produtos
printf("O valor total de A (R$ %.2f) é maior que o valor total de B (R$ %.2f)? %d\n", estoqueA*valorA, estoqueB*valorB, (estoqueA*valorA) > (estoqueB*valorB));

return 0;
}