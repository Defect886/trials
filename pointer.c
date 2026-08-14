#include <stdio.h>
#include <stdlib.h>
   int main(){
   int *A,n,x;
   scanf("%d", &n);
   A=(int *) malloc(n*sizeof(int));
   for(int i=0; i<n;i++){
    scanf("%d", &x);
    A[i]=x;
   }

   printf("%x %x %d %d %d", A, A+2, *A, *A+2, *(A+2));

   free(A);

   return 0;
   }
   
