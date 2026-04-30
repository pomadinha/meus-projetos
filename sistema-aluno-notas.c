#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#define QTD_NOTAS 3
#define MAX_ALUNOS 50
#define MEDIA_AP 7.0              

typedef struct{
    char nome[50];
    int matricula;               
    char turma[10];
    float notas[QTD_NOTAS];
    float media;
    char situacao[20];
}Aluno;

void cadastrarAluno(Aluno alunos[], int *qtd);
void gerencNotas(Aluno alunos[], int qtd);
void buscarAluno(Aluno alunos[], int qtd);
void relatorioGeral(Aluno alunos[], int qtd);
void desempenhoTurma(Aluno alunos[], int qtd);
void limparBuffer();

int main(){
    setlocale(LC_ALL, "Portuguese");

    Aluno alunos[MAX_ALUNOS];
    int qtd_alunos = 0;
    int opcao;

    do{
        printf("------ SISTEMA ACADÊMICO ------\n");
        printf("1. Cadastrar Aluno\n");
        printf("2. Inserir/Atualizar Notas\n");
        printf("3. Buscar Aluno\n");
        printf("4. Relatório Geral\n");
        printf("5. Desempenho da Turma\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                cadastrarAluno(alunos, &qtd_alunos);
                break;
            case 2:
                gerencNotas(alunos, qtd_alunos);   
                break;
            case 3:
                buscarAluno(alunos, qtd_alunos);
                break;
            case 4:
                relatorioGeral(alunos, qtd_alunos);
                break;
            case 5:
                desempenhoTurma(alunos, qtd_alunos);
                break;
            case 0:
                printf("Encerrando Sistema...\n");
                break;
            default:
                printf("Opção Inválida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}

void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrarAluno(Aluno alunos[], int *qtd){
    if (*qtd >= MAX_ALUNOS) {
        printf("ERRO! CAPACIDADE MÁXIMA DE ALUNOS ATINGIDA!\n");
        return;
    }
    printf("--- CADASTRO ALUNO ---\n");
    printf("Matrícula: ");
    scanf("%d", &alunos[*qtd].matricula);
    limparBuffer();

    printf("Nome: ");
    fgets(alunos[*qtd].nome, sizeof(alunos[*qtd].nome), stdin);
    alunos[*qtd].nome[strcspn(alunos[*qtd].nome, "\n")] = '\0';

    printf("Turma: ");
    fgets(alunos[*qtd].turma, sizeof(alunos[*qtd].turma), stdin);
    alunos[*qtd].turma[strcspn(alunos[*qtd].turma, "\n")] = '\0';

    alunos[*qtd].media = 0.0;
    strcpy(alunos[*qtd].situacao, "Sem notas");

    (*qtd)++;                  
}

void gerencNotas(Aluno alunos[], int qtd){
    if (qtd == 0){
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    int mat, indice = -1;
    printf("\nDigite a matrícula do aluno para lançar as notas: ");
    scanf("%d", &mat);
    limparBuffer();

    for (int i = 0; i < qtd; i++){
        if (alunos[i].matricula == mat){
            indice = i;               
            break;
        }
    }if (indice == -1){
        printf("Aluno não encontrado.\n");
        return;
    }

    float soma = 0;
    printf("Lançamento de notas para: %s\n", alunos[indice].nome);
    for (int i = 0; i < QTD_NOTAS; i++){
        printf("Nota %d: ", i + 1);
        scanf("%f", &alunos[indice].notas[i]);
        soma += alunos[indice].notas[i];
    }

    alunos[indice].media = soma / QTD_NOTAS;
    if(alunos[indice].media >= MEDIA_AP){   
        strcpy(alunos[indice].situacao, "Aprovado");
    }else{
        strcpy(alunos[indice].situacao, "Reprovado");
    }
    printf("Notas atualizadas, a média é: %.2f (%s)\n", alunos[indice].media, alunos[indice].situacao);
}

void buscarAluno(Aluno alunos[], int qtd){
    if (qtd == 0) {
        printf("Nenhum aluno foi cadastrado.\n");
        return;
    }

    int tipo;
    printf("\nSelecione busca por matrícula (1) ou nome (2): ");
    scanf("%d", &tipo);
    limparBuffer();

    int encontrou = 0;                    

    if(tipo == 1) {
        int mat;
        printf("Digite a matrícula: ");
        scanf("%d", &mat);
        for(int i = 0; i < qtd; i++) {
            if(alunos[i].matricula == mat) {
                printf("\nMatrícula: %d | Nome: %s | Turma: %s | Média: %.2f | Status: %s\n", alunos[i].matricula, alunos[i].nome, alunos[i].turma, alunos[i].media, alunos[i].situacao);
                encontrou = 1;
                break;
            }
        }
    }else if (tipo == 2){
        char nomeBusca[50];
        printf("Digite o nome: ");
        fgets(nomeBusca, sizeof(nomeBusca), stdin);
        nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

        for(int i = 0; i < qtd; i++) {
            if(strstr(alunos[i].nome, nomeBusca) != NULL){
                printf("\nMatrícula: %d | Nome: %s | Turma: %s | Média: %.2f | Status: %s\n", alunos[i].matricula, alunos[i].nome, alunos[i].turma, alunos[i].media, alunos[i].situacao);
                encontrou = 1;
                break;
            }
        }
    } else{
        printf("Tipo de busca inválido.\n");
        return;
    }if(!encontrou)
        printf("Nenhum registro foi encontrado.\n");
}

void relatorioGeral(Aluno alunos[], int qtd){
    if(qtd == 0){
        printf("Nenhum aluno cadastrado.\n");
        return;
    }
    printf("\n--- RELATORIO GERAL DA TURMA ---\n");
    printf("%-10s | %-20s | %-10s | %-6s | %s\n", "Matricula", "Nome", "Turma", "Media", "Situacao");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < qtd; i++) {
        printf("%-10d | %-20s | %-10s | %-6.2f | %s\n",
               alunos[i].matricula, alunos[i].nome, alunos[i].turma,
               alunos[i].media, alunos[i].situacao);
    }
}

void desempenhoTurma(Aluno alunos[], int qtd){
    if(qtd == 0){
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    float maior = alunos[0].media;
    float menor = alunos[0].media;
    float somaTurma = 0;
    int aprovados = 0, reprovados = 0;

    for(int i = 0; i < qtd; i++){
        if(alunos[i].media > maior) maior = alunos[i].media;
        if(alunos[i].media < menor) menor = alunos[i].media;
        somaTurma += alunos[i].media;

        if(strcmp(alunos[i].situacao, "Aprovado") == 0) aprovados++;
        if(strcmp(alunos[i].situacao, "Reprovado") == 0) reprovados++;
    }

    printf("\n--- ESTATISTICAS GERAIS ---\n");
    printf("Total de Alunos: %d\n", qtd);
    printf("Maior Media: %.2f\n", maior);
    printf("Menor Media: %.2f\n", menor);
    printf("Media Geral da Turma: %.2f\n", somaTurma / qtd);
    printf("Taxa de Aprovacao: %.1f%%\n", ((float)aprovados / qtd) * 100);
}
