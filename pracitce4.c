#include <stdio.h>

int result(int s, int v){

    int const u=1, f=2;
    int t;
    
    printf("Horizontal bar for v\n");
    for(t=0;t<=3;t++){
         v = u + f*t;
         
         for(int j=0; j<v; j++){
            printf("*");
         }
         printf("\n");
    }
    printf("\n");
    printf("Horizontal bar for s\n");
    for(t=0;t<=3;t++){
         s=(u*t) + (1.0/2.0*f*t*t);
         
         for(int j=0; j<s; j++){
            printf("*");
         }
         printf("\n");

    }
}

int main(){
    int s,v,t,u,f;

    result(s,v); 
    return 0;
}