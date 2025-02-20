#include <stdio.h>

int main(){
    
    char estado [2]; //uma letra de A até H
    char codigo [4]; //um número de 01 a 04
    char cidade [15];
    int populacao;
    float area; //área do estado em km²
    float pib; 
    int pt; //pontos turísticos
    
    
    printf("Escolha uma letra de A até H para representar o Estado: \n"); 
    scanf("%s", estado); //em strings não é necessário o uso de &
    
    printf("Informe um número de 01 a 04: \n"); 
    scanf("%s", codigo); //em strings não é necessário o uso de &
    
    printf("Informe o nome da cidade: \n");
    scanf("%s", cidade); //em strings não é necessário o uso de &
    
    printf("Informe a população da cidade escolhida: \n");
    scanf("%d", &populacao);
    
    printf("Informe a área da população em km²: \n");
    scanf("%f", &area);
    
    printf("Informe o PIB do Estado: \n");
    scanf("%f", &pib);
    
    printf("Informe a quantidade de pontos turísticos do Estado: \n");
    scanf("%d", &pt);
    
    //////////////////////////////////////////////////////////////////
    
    printf("Escolha uma letra de A até H para representar o 2º Estado: \n"); 
    scanf("%s", estado); //em strings não é necessário o uso de &
    
    printf("Informe um número de 01 a 04: \n"); 
    scanf("%s", codigo); //em strings não é necessário o uso de &
    
    printf("Informe o nome da cidade: \n");
    scanf("%s", cidade); //em strings não é necessário o uso de &
    
    printf("Informe a população da cidade escolhida: \n");
    scanf("%d", &populacao);
    
    printf("Informe a área da população em km²: \n");
    scanf("%f", &area);
    
    printf("Informe o PIB do Estado: \n");
    scanf("%f", &pib);
    
    printf("Informe a quantidade de pontos turísticos do Estado: \n");
    scanf("%d", &pt);
    
    //parte em que as informações descritas serão exibidas
    
    printf("Carta 1\n");
    printf("Estado: %s\n", estado);
    printf("Código: %s%s\n", estado, codigo); //os identificadores tem que ficar juntas pois os valores são juntos
    printf("Cidade: %s\n", cidade);
    printf("População: %.2d\n", populacao);
    printf("Área: %2.fkm²\n", area);
    printf("PIB: %.2f Bilhões de reais\n", pib);
    printf("Pontos Turísticos: %d\n", pt);
    
    ////////////////////////////////////////////////////////////////////////////
    
    printf("\nCarta 2\n");
    printf("Estado: %s\n", estado);
    printf("Código: %s%s\n", estado, codigo); //os identificadores tem que ficar juntas pois os valores são juntos
    printf("Cidade: %s\n", cidade);
    printf("População: %.2d\n", populacao);
    printf("Área: %2.fkm²\n", area);
    printf("PIB: %.2f Bilhões de reais\n", pib);
    printf("Pontos Turísticos: %d\n", pt);
    
    return 0;
}
