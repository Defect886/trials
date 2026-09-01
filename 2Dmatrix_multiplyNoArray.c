#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

void allocation_matrix(int ***a,int m, int n){
    *a=(int **)malloc(m*sizeof(int *));
   

    assert(*a!=NULL);

    for(int i=0;i<m;++i){
        *(*a+i)=(int *)malloc(n*sizeof(int));
        assert(*(*a+i)!=NULL);
        
    }

}

void take_input(int ***a, int m,int n){
   allocation_matrix(a,m,n);
    
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            scanf("%d", (*(*a+i)+j));
        }
    }

}

void print(int **a, int m, int n){
     for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            printf("%d ",*(*(a+i)+j));
        }
        printf("\n");
    }
}

void freearray(int m, int **a){
    for(int i=0; i<m;i++){
        if(*(a+i)!=NULL) free(*(a+i));
    }
    if (a!=NULL) free(a);
}

void multiply(int ***c, int m, int n, int k, int **a, int **b){
    allocation_matrix(c,m,n);
    
    

    for(int i=0; i<m; i++){
        for(int j=0; j<m;j++){
            int sum=0;
            for(int l=0; l<k; l++){
                sum+= (*(*(a+i)+l))*(*(*(b+l)+j));
            }
            *(*(*c+i)+j)=sum;
        }
    }
}

int main(){
    int **a,**b,**c;
    take_input(&a, 4, 3);
    take_input(&b, 3, 4);
    multiply(&c, 4, 4, 3, a, b);

    print(c, 4, 4);

    freearray(4,a);
    freearray(3,b);
    freearray(4,c);
    return 0;
}





