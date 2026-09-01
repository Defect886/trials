#include <stdio.h>
#include <string.h>

char mostFrquentChar(char str[]){

    int i=0;
    int x=0;
    int max=0;
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

        
        

        for(int j=start; j<=end; j++){
            int count=1;
            for(int k=j+1; k<=end; k++){
                if (str[j]==str[k]){
                    count++;
                }
            }if(count>max){
                max=count;
                x=j;
            }
            

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
        printf("Most frequent character in the one word: %c", result);
        return 0;
    }