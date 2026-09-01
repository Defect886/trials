#include <stdio.h>
#include <string.h>

int removeShortestWord(char str[]){
     int i=0;
     int shortestLength=1000;
     int shortestStart=-1;
     int shortestEnd=-1;
    
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

        int length=end-start+1;
        if(length<shortestLength){
            shortestLength=length;
            shortestStart=start;
            shortestEnd=end;
        }
}

    if(shortestStart!=-1){
        for(int j=shortestEnd+1; str[j]!='\0'; j++){
            str[shortestStart]=str[j];
            shortestStart++;
        }
        str[shortestStart]='\0';
    }
    return shortestLength;
}

int main(){
    char str[100];
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")]='\0';
    int length=removeShortestWord(str);
    printf("Modified sentence: %s\n", str);
    printf("Length of the removed word: %d\n", length);
    return 0;
}