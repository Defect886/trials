#include <stdio.h>
#include <string.h>

int No_Vowel_Number(char str[]){
    int i=0;
    int count=0;
    while(str[i]!= '\0'){
        char c= str[i];
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
            return 0;
        }
        if(c>= '0' && c<= '9'){
            return 0;
        }
        i++;
    }
    return 1;
}

void findlongestnoVowelSubstring(char str[]){
    int i=0;
    int start=-1;

    int best_start=-1;
    int best_length=0;
    while(str[i]!='\0'){
        char temp[2];
        temp[0]=str[i];
        temp[1]='\0';

    if(No_Vowel_Number(temp)){
    if(start==-1){
        start=i;          
    }
    
}
else{
    if(start!=-1){
        int length=i-start;
        if(length>=best_length){
            best_length=length;
            best_start=start;
        }
    }
    start=-1;       
        }
        i++;
    }

    if(start!=-1){
                    int length=i-start;
                    if(length>=best_length){
                        best_length=length;
                        best_start=start;
                    }
                    
                }

    if(best_start==-1){
        printf("No substring found without vowels and numbers.\n");
    }
    else{
        char result[100];
        int k=0;
        printf("Longest substring without vowels and numbers: ");
        for(int j=best_start;j<best_start+best_length;j++){
            result[k]=str[j];
            k++;
        }
        result[k]='\0';
        printf("%s\n", result);
    }
}

int main(){
    
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")]='\0';
    findlongestnoVowelSubstring(str);
    return 0;
}