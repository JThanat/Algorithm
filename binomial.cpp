#include <stdio.h>

int c[35][35];

int bin(int n , int k) {
    if(k == 0 || k == n) return 1;
    if(c[n][k] != 0) return c[n][k];
    return c[n][k] = bin(n-1,k-1) + bin(n-1,k);
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 0 ; i <= n ; i++) {
        for(int j = 0 ; j <= k ; j++) {
            if(j==0 || j==i) c[i][j] = 1;
            else c[i][j] = c[i-1][j-1] + c[i-1][j];
        }
    }

    // for(int i = 0 ; i <= n ; i++) {
    //     for(int j = 0 ; j <= n ; j++) {
    //         printf("%d ",c[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d ",c[n][k]);
    
    // printf("%d",bin(n,k));
    return 0;
}
