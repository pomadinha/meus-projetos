#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUTO 100

typedef struct{
	int codigo;
	int quantidade;
	char nome[50];
	float preco;
} Produto;

Produto estoque[MAX_PRODUTO];
int total_produtos = 0;

void cadastroProduto(){
	if(total_produtos >= MAX_PRODUTO){
		printf("Limite de produtos atingido.\n");
		return;
	}
	Produto p;
	printf("\n--- CADASTRO DE PRODUTO ---\n");
	
	p.codigo = total_produtos + 1;
	
	while (getchar() != '\n'); 
	
	printf("Nome do produto: ");
	scanf("%[^\n]", p.nome); 
	
	printf("Quantidade: ");
	scanf("%d", &p.quantidade);
	printf("Preço: ");
	scanf("%f", &p.preco);
	
	estoque[total_produtos] = p;
	total_produtos++;
	
	printf("Produto cadastrado com código %d\n\n", p.codigo); 
}

void listarEstoque(){
	printf("\n--- ESTOQUE DE PRODUTOS ---\n");
	if(total_produtos == 0){
		printf("Nenhum produto cadastrado.\n\n");
		return;
	}
	printf("%-10s %-20s %-15s %-10s\n", "CODIGO", "NOME", "QUANTIDADE", "PRECO");
	printf("--------------------------------------------------------------\n");
	for(int i = 0; i < total_produtos; i++){
		printf("%-10d %-20s %-15d R$%-8.2f\n", estoque[i].codigo, estoque[i].nome, estoque[i].quantidade, estoque[i].preco);
	}
	printf("\n");
}

void registrarVenda(){
	printf("\n--- REGISTRO DE VENDAS ---\n");
	if(total_produtos == 0){
		printf("OPERACAO INVALIDA: Nenhum produto no estoque.\n\n");
		return;
	}
	int codigo_busca, qtd_venda, encontrado = 0;
	
	printf("CODIGO DO PRODUTO: ");
	scanf("%d", &codigo_busca);
	
	for(int i = 0; i < total_produtos; i++){ 
		if(estoque[i].codigo == codigo_busca){
			encontrado = 1;
			printf("PRODUTO ENCONTRADO: %s (Estoque: %d)\n", estoque[i].nome, estoque[i].quantidade);
			printf("QUANTIDADE DE VENDAS: ");
			scanf("%d", &qtd_venda); 
			
			if(qtd_venda > estoque[i].quantidade){
				printf("QUANTIDADE EM ESTOQUE INSUFICIENTE.\n");
			}else if(qtd_venda <= 0){
				printf("QUANTIDADE DE VENDAS DEVE SER MAIOR QUE ZERO.\n");
			}else{
				estoque[i].quantidade -= qtd_venda;
				float total_venda = qtd_venda * estoque[i].preco;
				printf("VENDA REALIZADA COM SUCESSO!\n");
				printf("Total a pagar: R$%.2f\n", total_venda);
				printf("NOVO ESTOQUE DE %s: %d\n", estoque[i].nome, estoque[i].quantidade);
			}
			break;
		}
	}
	if(!encontrado){
		printf("PRODUTO DE CODIGO %d NAO ENCONTRADO\n", codigo_busca); 
	}
	printf("\n");
}

int main(){
	int opcao;
	
	do{
		printf("--- GERENCIAMENTO DE VENDAS ---\n");
		printf("1. CADASTRAR PRODUTOS\n");
		printf("2. CONSULTAR ESTOQUE\n");
		printf("3. REGISTRAR VENDA\n");
		printf("4. SAIR\n");
		printf("Escolha uma opcao acima: ");
		scanf("%d", &opcao);
		
		switch (opcao){
			case 1:
				cadastroProduto();
				break;
			case 2:
				listarEstoque();
				break;
			case 3:
				registrarVenda();
				break;
			case 4:
				printf("ENCERRANDO SISTEMA\n");
				break;
			default:
				printf("OPCAO INVALIDA\n\n");
		}
	}while(opcao != 4);
	
	return 0;
}
