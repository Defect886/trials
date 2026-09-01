#include <stdio.h>
#include <string.h>

void capitalizeWords(char str[]){
    int i=0;
    while(str[i]!='\0'){
        while(str[i]==' '){
            i++;
        }
        if(str[i]=='\0'){
            break;
        }
        int start=i;
        
        str[start]=str[start]-32;

        while(str[i]!=' ' && str[i]!='\0'){
            i++;
        }
    }
}

int main(){
    char str[100];
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")]='\0';
    capitalizeWords(str);
    printf("Modified sentence: %s", str);
    return 0;
}