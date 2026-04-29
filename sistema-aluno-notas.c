#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define QTD_NOTAS 3
#define QTD_ALUNOS 30
#define MEDIA_AP 7.0

typedef struct{
  int matricula; 
  char situacao[15];
  char nome[50]; 
  char turma[20]; 
  float notas [QTD_NOTAS]; 
  float media;
}Aluno;

void cadAlunos(Aluno alunos[], int *qtd);
void gerencNotas(Aluno alunos[], int qtd); 
void buscarAluno(Aluno alunos[], int qtd); 


///////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////
void gerencNotas(Aluno alunos[], int qtd){
  if(qtd == 0){
    printf("Nenhum aluno cadastrado.");
    return;
  }
  
  int mat, indice = -1;
  printf("\nDigite a matrícula do aluno para lançar as notas: ");
  scanf("%d", &mat);

  for(int i = 0; i < qtd; i++){
    if(alunos[i].matricula == mat){
      indice = 1;
      break;
    }
  }

  if (indice == - 1){
    printf("Aluno não encontrado.\n");
    return;
  }

  float soma = 0;
  printf("Lançamento de notas para: %s\n", alunos[indice].nome);
  for(int i = 0; i < QTD_NOTAS; i++){
    printf("Nota %d: ", i+1);
    scanf("%f", &alunos[indice].notas[i]);
    soma += alunos[indice].notas[i];
  }

  alunos[indice].media = soma/QTD_NOTAS;
  if(alunos[indice].media >= MEDIA_AP){
    strcpy(alunos[indice].situacao, "Aprovado.\n");
  }else{
    strcpy(alunos[indice].situacao, "Reprovado.\n");
  }
  printf("Notas atualizadas, a média é: %.2f(%s)\n", alunos[indice].media, alunos[indice].situacao);
}
///////////////////////////////////////////////////////
void buscarAlunos(Aluno aluno[], int qtd){
  if(qtd == 0){
    printf("Nenhum aluno foi cadastrado.\n");
  }
  
  int tipo;
  printf("\nSelecione busca por matrícula(1) ou nome(2).");
  scanf("%d", &tipo);
  limparBuffer();

  int encontrou == 0;

  if(tipo == 0){
    int mat;
    printf("Digite a matrícula: ");
    scanf("%d", &mat);
    for(int i = 0; i < qtd; i++){
      if(alunos[].matricula == mat){
        printf("\nMatrícula: %d | Nome: %s | Turma: %s | Média: %.2f | Status: %s\n", alunos[i].matricula, alunos[i].nome, alunos[i].turma, alunos[i].media, alunos[i].situacao);
        encontrou = 1;
        break;
      }
    }
  }else if(tipo == 2){
    char nomeBusca[50];
    printf("Digite o nome: ");
    fgets(nomeBusca, 50, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = 0

      for(int i = 0; i  < qtd; i++){
        if(strstr(alunos[i].nome, nomeBusca) != NULL){
          printf("\nMatrícula: %d | Nome: %s | Turma: %s | Média: %.2f | Status: %s\n", alunos[i].matricula, alunos[i].nome, alunos[i].turma, alunos[i].media, alunos[i].situacao);
          encontrou = 1;
          break;
        }
      }
  }
if(!encontrou) printf("Nenhum registro foi encontrado.\n");
}
///////////////////////////////////////////////////////
