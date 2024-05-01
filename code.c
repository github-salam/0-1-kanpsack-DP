#include <stdio.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int knapsack(int m, int n, int p[], int wt[]){
    int k[n+1][m+1];

    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= m; w++){
            if(i == 0 || w == 0) k[i][w] = 0;
            else if(wt[i] <= w) k[i][w] = max(k[i-1][w], p[i] + k[i-1][w-wt[i]]);
            else k[i][w] = k[i-1][w];
        }
    }

    return k[n][m];
}

int main(){ 

    int profit[] = {0,60,100,120};
    int weight[] = {0,10,20,30};
    int n = 3;
    int capacity = 50;
    int maxP;
    maxP = knapsack(capacity,n,profit,weight);
    printf("Max profit : %d\n", maxP);

    return 0;
}