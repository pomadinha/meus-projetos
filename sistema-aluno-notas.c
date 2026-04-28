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

void cadAlunos();
void gerencNotas();
void buscarAluno();

