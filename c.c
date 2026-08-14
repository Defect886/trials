#include <stdio.h>
int main(){
    char ch;
    int count=0;
    for(int i=0; i<4; i++)
    {
        printf("Enter your Character:\n");
        scanf(" %c", &ch);
        if(ch>='0' && ch<='9'){
            count++;
        }
    }

    printf("%d of them are numbers", count);
    return 0;
}