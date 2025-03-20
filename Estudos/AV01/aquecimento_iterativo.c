#include <stdio.h>
#define TAM_MAX 50
#include <string.h>

int contar_iterativo(char str[]){
    int total = 0;
    for(int i = 0; i < strlen(str); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            total++;
        }
    }
    return total;
}

int main(){
    char str[TAM_MAX];
    while(1){
        scanf("%[^\n]", str);
    if (strcmp(str, "FIM") == 0) {
            break;
    }
    printf("%d", contar_iterativo(str));
    }
}
