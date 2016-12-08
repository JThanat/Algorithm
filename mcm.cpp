#include <stdio.h>

int p[105];
int mcm[105][105];

int min(int a, int b) {
    // negative value represents infinity
    if(a < 0) return b;
    else if (b < 0) return a;
    else return a < b ? a : b;
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i <= n ;i++) {
        scanf("%d",&p[i]);
    }
    for(int j = 1 ; j <= n ; j++) {
         for(int i = j ; i >= 1 ; i--) {
             if(i == j) {
                 mcm[i][j] = 0;
             } else {
                 int minN = -1;
                 for(int k = i ; k < j ; k++) {
                     minN = min(minN , mcm[i][k] + mcm[k+1][j] + p[i-1]*p[k]*p[j] );
                 }
                 mcm[i][j] = minN;
             }
         }
    }
    // for(int i = 1 ; i <= n ;i++) {
    //     for(int j = 1 ; j <= n ; j++) {
    //         printf("%d\t",mcm[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d",mcm[1][n]);

    return 0;
}