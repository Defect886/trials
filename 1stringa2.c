#include <stdio.h>
#include <string.h>

void swapWordEnds(char str[]){
    int i=0;
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

        int temp=str[start];
        str[start]=str[end];
        str[end]=temp;

    }
    
}

int main(){
    char str[100];
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")]='\0';
    swapWordEnds(str);
    printf("Modified sentence: %s", str);
    return 0;

}