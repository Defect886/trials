#include <stdio.h>
#include <stdlib.h>
int main(){
    int *A,x, tempmax1=0,tempmax2=0;
    A=(int*) malloc(5*sizeof(int));
    
    for(int i=0; i<5; i++){
        scanf("%d", (A+i));
    }


    for(int j=0; j<5; j++){
        for(int k=j+1; k<=4; k++){
            

        if(abs(*(A+j)-*(A+k))<tempmax1 || abs(*(A+j)-*(A+k))>tempmax1){
                tempmax1= abs(*(A+j)-*(A+k));
            }
            
            else if(*(A+j) == *(A+k)){
                tempmax1= 0;
            }

        if(tempmax1>tempmax2){
                tempmax2=tempmax1;
            }

            


        }
    }

    printf("%d", tempmax2);
    free(A);

    return 0;

}