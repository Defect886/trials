#include <stdio.h>
#include <string.h>

int countEveWords(char str[]){

    int i=0;
    int count=0;
    while(str[i]!='\0'){
        while(str[i]==' '){
            i++;
        }
        if(str[i]=='\0'){
            break;
        }
        int start=i;
        while(str[i]!=' ' && str[i]!='\0'){
            i++;
        }
        int end=i-1;

        if((end-start+1)%2==0){
            count++;

        }
    }
    return count;
}
int main(){
    char str[100];
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")]='\0';
    int result = countEveWords(str);
    printf("Number of words with even length in the sentence: %d", result);
    return 0;
}

