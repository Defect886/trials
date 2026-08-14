#include <stdio.h>
#include <stdlib.h>
int* square(int a){
    int *result= malloc(sizeof(int));
    *result=a*a;
    return result;
}
int main(){
    int *(*f)(int a)= square;
    int *ptr= f(5);
    printf("%d", *ptr);
    free(ptr);
    return 0;
}


//