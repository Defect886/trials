#include <stdio.h>
#include <stdlib.h>
int main(){
    int **A, row, col,x;

    scanf("%d %d", &row, &col);

    A=(int **) malloc(row* sizeof(int));



    for(int i=0; i<row; i++){
        A[i]=(int*) malloc(col* sizeof(int));
        }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &x);
            A[i][j] = x;
        }
    }


    

    printf("%d %d %p %p %d %p %p %p", A[2][1], *(*(A+2)+1), A, (void*)A, **A, (A+1), (void*)A+1, (void*)(A+1));
    return 0;

    free(A);

    return 0;
}