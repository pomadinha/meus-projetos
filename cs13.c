#include <stdio.h>

int main(){
  int index;
  char * nomeAlunos [3][3] = {
    {"Aluno 0", "PT: 30", "MAT: 80"}, 
    {"Aluno 1", "PT: 80", "MAT: 50"}, 
    {"Aluno 2", "PT: 80", "MAT: 80"}
  };

  printf("Digite o número do aluno que queira ver as notas: \n");
  printf("Para aluno 0, digite 0.\n");
  printf("Para aluno 1, digite 1.\n");
  printf("Para aluno 2, digite 2.\n");

  scanf("%d", &index);

  printf("As notas do %s são: %s, %s \n", nomeAlunos[index][0], nomeAlunos[index][1], nomeAlunos[index][2]);
  return 0;
}