#include <stdio.h>
int main(){
    void *ptr;
    int i=123; double j= 123.123;
    int *ptri;
    double *ptrd;

    ptr= (void *) &i;
    ptri=(int *) ptr;

    printf("%d\n", *ptri);

    ptr= (void *) &j;
    ptrd=(double *) ptr;

    printf("%lf", *ptrd);

    return 0;

}