#include <stdio.h>

int main() {
    
    char txt[100];
    int i = 0;

    printf("Digite uma frase ou palavra: ");
    fgets(txt, sizeof(txt), stdin);

    while (txt[i] != '\0' && txt[i] != '\n'){
        i++;
    }

    printf("A string digitada possui %d caracteres.\n", i);

    return 0;
}


