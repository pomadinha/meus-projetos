#include <stdio.h>

int main(){
    
    int idade, matricula;
    float altura;
    char nome[50];
    
    printf("Informe sua idade: \n");
    scanf("%d", &idade);
    
    printf("Informe sua altura: \n");
    scanf("%f", &altura);
    
    printf("Digite seu nome: \n");
    scanf("%s", nome);
    
    printf("Informe sua matrícula: \n");
    scanf("%d", &matricula);
    
    printf("Nome do aluno - %s || Matrícula do aluno - %d\n", nome, matricula);
    printf("Idade do aluno - %d || Altura do aluno - %.2f", idade, altura);

    return 0;
}
