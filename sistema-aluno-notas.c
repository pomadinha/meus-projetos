#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define QTD_NOTAS 3
#define QTD_ALUNOS 30
#define MEDIA_FINAL 7.0

typedef struct{
  int matricula; 
  char situacao[15];
  char nome[50]; 
  char turma[20]; 
  float notas [QTD_NOTAS]; 
  float media;
}Aluno;

void cadAlunos(Aluno alunos[], int *qtd);
void gerencNotas(Aluno alunos[], int qtd); //ainda falta 
void buscarAluno(Aluno alunos[], int qtd); //ainda falta

void cadAlunos(Aluno alunos[], int *qtd){
  if(*qtd >= QTD_ALUNOS){
    printf("ERRO! CAPACIDADE MÁXIMA DE ALUNOS ATINGIDA!\n")
      return;
  }

  printf("--- CADASTRO ALUNO ---\n");
  prtinf("Matrícula: ");
  scanf("%d", &alunos[*qtd].matricula);
  limparBuffer();

  printf("Nome: ");
  fgets(alunos[*qtd].nome, 50, stdin);
  alunos[*qtd].nome[strcspn(alunos[*qtd].nome,"\n")] = 0;

  printf("Turma: ");
  fgets(alunos[*qtd].turma, 20, stdin);
  alunos[*qtd].turma[strcspn(alunos[*qtd].turma,"\n")] = 0;

  for(int i = 0; i < QTD_NOTAS; i++){
    alunos[*qtd].notas[i] = 0.0;
  }
  alunos[*qtd].media = 0.0;
  strcpy(alunos[*qtd].situacao, "Sem notas.");

  (*qtd)++;
  printf("Aluno cadastrado com sucesso.\n");
}

