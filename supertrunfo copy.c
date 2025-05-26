#include <stdio.h>

int main(){
    
    char estado [2], estado2 [2]; //uma letra de A até H
    char codigo [4], codigo2 [4]; //um número de 01 a 04
    char cidade [15], cidade2 [15];
    unsigned long int populacao, populacao2;
    float area, area2, pib, pib2, densidade, densidade2, pcapita, pcapita2, superPoder1, superPoder2; //área do estado em km²
    int pt, pt2, resultadoA, resultadoB, resultadoC, resultadoD, resultadoE, resultadoF, resultadoG;
    
    ////////////////////// CARTA 1 /////////////////////////////////////////
    printf("Escolha uma letra de A até H para representar o 1ª Carta: \n"); 
    scanf("%s", estado); //em strings não é necessário o uso de &
    printf("Informe um número de 01 a 04: \n"); 
    scanf("%s", codigo); //em strings não é necessário o uso de &
    printf("Informe o nome da cidade: \n");
    scanf("%s", cidade); //em strings não é necessário o uso de &
    printf("Informe a população da cidade escolhida: \n");
    scanf("%lu", &populacao);
    printf("Informe a área da população em km²: \n");
    scanf("%f", &area);
    printf("Informe o PIB do Estado: \n");
    scanf("%f", &pib);
    printf("Informe a quantidade de pontos turísticos do Estado: \n");
    scanf("%d", &pt);
    
    ////////////////////// CARTA 2 /////////////////////////////////////////
    printf("Escolha uma letra de A até H para representar a 2ª Carta: \n"); 
    scanf("%s", estado2); //em strings não é necessário o uso de &
    printf("Informe um número de 01 a 04: \n"); 
    scanf("%s", codigo2); //em strings não é necessário o uso de &
    printf("Informe o nome da cidade: \n");
    scanf("%s", cidade2); //em strings não é necessário o uso de &
    printf("Informe a população da cidade escolhida: \n");
    scanf("%lu", &populacao2);
    printf("Informe a área da população em km²: \n");
    scanf("%f", &area2);
    printf("Informe o PIB do Estado: \n");
    scanf("%f", &pib2);
    printf("Informe a quantidade de pontos turísticos do Estado: \n");
    scanf("%d", &pt2);

    //cálculos de pib per capita e densidade 
    densidade = populacao/area;
    densidade2 = populacao2/area2;
    pcapita = pib/populacao;
    pcapita2 = pib2/populacao2;

    //cálculo de super poderes e comparação de atributos 
    superPoder1 = populacao + area + pib + pt + pcapita + (1/densidade);
    superPoder2 = populacao2 + area2 + pib2 + pt2 + pcapita2 + (1/densidade2);

    resultadoA = populacao > populacao2;
    resultadoB = area > area2;
    resultadoC = pib > pib2;
    resultadoD = pt > pt2;
    resultadoE = densidade < densidade2;
    resultadoF = pcapita > pcapita2;
    resultadoG = superPoder1 > superPoder2;
    
    //parte em que as informações descritas serão exibidas
    /////////////////////////////// CARTA 1 /////////////////////////////////////////
    printf("\nCarta 1 \n");
    printf("Estado: %s\n", estado);
    printf("Código: %s%s\n", estado, codigo); //os identificadores tem que ficar juntas pois os valores são juntos
    printf("Cidade: %s\nPopulação: %d\n",cidade, populacao);
    printf("Área: %.2fkm²\nPIB: %.2f Bilhões de reais\n", area, pib);
    printf("Pontos Turísticos: %d\nDensidade Populacional: %.2f hab/km²\n", pt, densidade);
    printf("PIB per Capita: %.2f reais\n", pcapita);
    
    /////////////////////////////// CARTA 2 /////////////////////////////////////////
    printf("\nCarta 2 \n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s%s\n", estado2, codigo2); //os identificadores tem que ficar juntos pois os valores são juntos
    printf("Cidade: %s\nPopulação: %d\n",cidade2, populacao2);
    printf("Área: %.2fkm²\nPIB: %.2f Bilhões de reais\n", area2, pib2);
    printf("Pontos Turísticos: %d\nDensidade Populacional: %.2f hab/km²\n", pt2, densidade2);
    printf("PIB per Capita: %.2f reais\n", pcapita2);
    
    ///// RESULTADO DO JOGO /////
    printf("\nComparação das Cartas\n");
    printf("População: %d\nÁrea: %d\n", resultadoA, resultadoB);
    printf("PIB: %d\nPonrtos Turísticos: %d\n", resultadoC, resultadoD);
    printf("Densidade Populacional: %d\nPIB per Capita: %d\n",resultadoE, resultadoF);
    printf("Super Poder: %.0f\n", resultadoG);
    
    return 0;
}