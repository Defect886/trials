#include <stdio.h>
int main(){
    //10th index

    unsigned int n;
    printf("Enter your number:");
    scanf("%u", &n);

    if((n&8)==0){
        printf("the 10th bit is 0");
    }else
    printf("the 10th bit is 1");

    return 0; 
    
}