#include <stdio.h>
#include <string.h>

void replaceMiddle(char str[], char ch){

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
        if((end-start)%2==0){
            int mid=(start+end)/2;
            str[mid]=ch;
        }
        
    }
}

int main(){
    char str[100];
    char ch;
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")]= '\0';
    printf("Enter a character to replace the middle character of each word: ");
    scanf("%c", &ch);
    replaceMiddle(str, ch);
    printf("Modified sentence: %s", str);
    return 0;
}