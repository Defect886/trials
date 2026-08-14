#include <stdio.h>
int main(){
    int h;

    for(int i=0; i<4; i++){
        printf("Enter your first hexadecimal character:\n");
        scanf(" %x", &h);

        printf("%d\n", h);
    }
    return 0;
}