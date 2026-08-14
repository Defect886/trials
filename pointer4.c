#include <stdio.h>
#include <stdlib.h>
int main(){
    char str[100][10]={"apple", "banana", "melon", "mango", "kiwi"};

    for(int i=0; i<5; i++){
        printf("%s\n", str[i]);
    }

    printf("%c", str[2][3]);

    return 0;
}