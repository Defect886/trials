#include <stdio.h>
#include <string.h>

char mostFrquentChar(char str[]){

    int i=0;
    int x=0;
    int max=0;
    
    for(int i=0; i<strlen(str); i++){
        int count=1;
        if(str[i]==' '){
            continue;
        }
        for(int j=i+1; j<strlen(str); j++){
            if(str[i]==str[j]){
                count++;
            }
        }
        if(count>max){
            max=count;
            x=i;
        }
    }
    return str[x];
}
    int main(){
        char str[100];
        printf("Enter a sentence: ");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")]='\0';
        char result = mostFrquentChar(str);
        printf("Most frequent character in the sentence: %c", result);
        return 0;
    }