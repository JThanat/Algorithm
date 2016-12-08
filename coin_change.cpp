#include <stdio.h>
int coins[25];
int c[25][10005];

int min2(int a, int b) {
    return a < b ? a : b;
}
int min3(int a, int b, int c) {
    return min2(min2(a,b),c);
}
int main() {
    int n,v;
    scanf("%d %d",&n ,&v);
    for(int i = n ; i > 0; i--) {
        scanf("%d",&coins[i]);
    }

    for(int i = 0 ; i <= n ; i++) {
        for(int j = 0 ; j <= v ; j++) {
            int vi = coins[i];
            if(j <= 0 || i <= 0) {
                c[i][j] = 0;
                continue;
            }
            if(j != 0 && i == 1) {
                c[i][j] = j;
            }
            else if  (j < vi) c[i][j] = c[i-1][j];
            else{
                c[i][j] = min3(c[i-1][j], 1 + c[i][j-vi] , 1+ c[i-1][j-vi]);
            }
        }
    }
    printf("%d",c[n][v]);


    return 0;
}