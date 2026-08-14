#include <stdio.h>
int main(){
int N, M;
int ITEM_CODE=100, UNIT_PRICE=100, STOCK=100, Demand=100, Sold=100, Rem=100, Rev=100, Gross=100, Discount=100, INITIAL_STOCK=100;
int REQUESTED_ITEM_CODE, REQUESTED_QUANTITY;
int A[ITEM_CODE], B[UNIT_PRICE], C[STOCK], D[Demand], E[Sold], F[Rem], G[Rev], H[Gross], I[Discount], J[INITIAL_STOCK];
int served, finalbill;
int totalDemand=0, totalSold=0, grossSales=0, totalDiscount=0;
int full=0, partial=0, rejected=0, invalid=0;


scanf("%d %d", &N, &M);

if(N<1 || N>100 || M<1 || M>1000){
    printf("Menu items should be between 1 to 100 or Number of orders should be between 1 to 1000\n");
    return 0;
}

for(int i=0; i<N; i++){
    scanf("%d %d %d", &A[i], &B[i], &C[i]);
    J[i]=C[i];
    F[i]=C[i];
    if(A[i]<1 || A[i]>1000000000 || (i>0 && A[i]==A[i-1]) || B[i]<10 || B[i]>10000 || B[i]%10!=0 || C[i]<1 || C[i]>1000){
        printf("Invalid Input\n");
        return 0;
    }
}

for(int i=0; i<N; i++){
    D[i]=0;
    E[i]=0;
    F[i]=0;
    G[i]=0;
}

for(int i=0; i<M; i++){

    scanf("%d %d", &REQUESTED_ITEM_CODE, &REQUESTED_QUANTITY);

    if(REQUESTED_ITEM_CODE<1 || REQUESTED_ITEM_CODE>1000000000 || REQUESTED_QUANTITY<1 || REQUESTED_QUANTITY>1000){
        printf("Item code or Requested Quantity inavlid\n");
        return 0;
    }

    int found=0;

    for(int j=0; j<N; j++){
        if(REQUESTED_ITEM_CODE==A[j]){

            found=1;

            if(REQUESTED_QUANTITY <= C[j]){
                H[j]=REQUESTED_QUANTITY * B[j];
                if(REQUESTED_QUANTITY >= 5){
                    I[j]=H[j]*10/100;
                }
                else if(REQUESTED_QUANTITY < 5){
                    I[j]=0;
                }

                finalbill= H[j] - I[j];

                printf("Order %d: Item %d, FULL, requested=%d, served=%d, gross=%d, discount=%d, bill=%d\n",  i+1, REQUESTED_ITEM_CODE, REQUESTED_QUANTITY, REQUESTED_QUANTITY, H[j], I[j], finalbill );
                
                C[j]=C[j]-REQUESTED_QUANTITY;

                D[j]=D[j]+REQUESTED_QUANTITY;
                E[j]=E[j]+REQUESTED_QUANTITY;
                F[j]=C[j];
                G[j]=G[j]+finalbill;

                totalDemand=totalDemand+REQUESTED_QUANTITY;
                totalSold=totalSold+REQUESTED_QUANTITY;
                grossSales=grossSales+H[j];
                totalDiscount=totalDiscount+I[j];
                full++;

            }

            else if(REQUESTED_QUANTITY > C[j] && C[j]!=0){
                int served = C[j];
                H[j]=C[j] * B[j];
                    if(C[j] >= 5){
                    I[j]=H[j] * 10/100;
                }
                    else if(C[j] < 5){
                    I[j]=0;
                }

                    finalbill= H[j] - I[j];
                printf("Order %d: Item %d, PARTIAL, requested=%d, served=%d, gross=%d, discount=%d, bill=%d\n",  i+1, REQUESTED_ITEM_CODE, REQUESTED_QUANTITY, C[j], H[j], I[j], finalbill );

                C[j]=0;
                D[j]=D[j]+REQUESTED_QUANTITY;
                E[j]=E[j]+served;
                F[j]=C[j];
                G[j]=G[j]+finalbill;

                totalDemand=totalDemand+REQUESTED_QUANTITY;
                totalSold=totalSold+served;
                grossSales=grossSales+H[j];
                totalDiscount=totalDiscount+I[j];
                partial++;

            }
            else if(C[j]==0){
                printf("Order %d: Item %d, REJECTED, requested=%d, served = 0, gross = 0, discount = 0, bill = 0\n", i+1, REQUESTED_ITEM_CODE, REQUESTED_QUANTITY);
                D[j]=D[j]+REQUESTED_QUANTITY;
                totalDemand=totalDemand+REQUESTED_QUANTITY;
                rejected++;

            }

            break;

        }
    }
    if(!found){
        printf("Order %d: Item %d, INVALID, requested=%d, served = 0, gross = 0, discount = 0, bill = 0\n", i+1, REQUESTED_ITEM_CODE, REQUESTED_QUANTITY);
        invalid++;
    }
    

}

printf("\n");

for(int i=0; i<N; i++){
    printf("Item %d: demand=%d, sold=%d, remaining=%d, revenue=%d\n", A[i], D[i], E[i], F[i], G[i] );
}

printf("\n");

printf("Full orders: %d\n", full);
printf("Partial orders: %d\n", partial);
printf("Rejected orders: %d\n", rejected);
printf("Invalid orders: %d\n", invalid);
printf("Total valid demand: %d\n", totalDemand);
printf("Total units sold: %d\n", totalSold);

int lostDemand= totalDemand - totalSold;
printf("Lost demand: %d\n", lostDemand);
printf("Gross sales: %d\n", grossSales);
printf("Total Discount: %d\n", totalDiscount);

int netRev= grossSales - totalDiscount;
printf("Net Revenue: %d\n", netRev);

int mostDemanded = 0, bestSell=0, highestRev=0;
for(int i=1; i<N; i++){
    if(D[i] > D[mostDemanded] || (D[i] == D[mostDemanded] && A[i] < A[mostDemanded])){
     mostDemanded = i;}
    
    if(E[i] > E[bestSell] || (E[i] == E[bestSell] && A[i] < A[bestSell])){
     bestSell = i;}

    if(G[i] > G[highestRev] || (G[i] == G[highestRev] && A[i] < A[highestRev])){
     highestRev = i;}

}

if(totalDemand!=0){
printf("Most demanded item: %d with %d units\n", A[mostDemanded], D[mostDemanded]);}
else{
    printf("Most demanded item: NONE\n");
}
if(totalSold!=0){
printf("Best-selling item: %d with %d units\n", A[bestSell], E[bestSell]);}
else{
    printf("Best-selling item: NONE\n");
}
if(netRev!=0){
printf("High Revenue item: %d with %d BDT\n", A[highestRev], G[highestRev]);}
else{
    printf("Highest-revenue item: NONE\n");
}

int check=0;

printf("Items to restock: ");
for(int i=0; i<N; i++){
    if(F[i] <= J[i] * 20 / 100){
        printf("%d ", A[i]);
        check=1;
    }
}
if(check==0){
    printf("None\n");
}

return 0;



}