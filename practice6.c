#include <stdio.h>
int main(){
    char a;
    char x;

    printf("Enter a letter:\n");
    scanf("%c", &a);

    x=(char)((((a-97)+1)%26)+97);
    printf("%c",x);
}
