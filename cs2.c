#include <stdio.h>

int main(){
    
    int i = 0;

    while(i <= 20){
        if(i %2 == 0){ //== (igual a) != (diferente de) | %(divide e deixa o resto)
            printf("O número %d é par!\n", i);
        }
        i++;
    }

  return 0;
}