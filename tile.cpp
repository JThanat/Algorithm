#include <stdio.h>
int dp[15][10005];
int a[15];
int maxValue = 0;
int m;
int min(int a , int b) {
    if(a < 0) return b;
    else if(b < 0) return a;
    return a < b ? a : b;
}

int cost(int n , int m) {
    if(dp[n][m] != -5) return dp[n][m];
    if(n == 0 && m == 0) return dp[n][m] = 0;
    if(n == 0 && m != 0) return dp[n][m] = -1;

    int minN = -1;
    for(int i = 1 ; i < maxValue ; i++) {
        int restArea = m-i*i;
        if(restArea < 0) continue;  
        int curChangeCost = (i-a[n-1])*(i-a[n-1]);
        int restChangeCost = cost(n-1 , restArea);
        if(restChangeCost >= 0) {
            minN = min(minN, curChangeCost + restChangeCost);
        }
    }
    return dp[n][m] = minN;
}   


int main() {
    int n;
    scanf("%d %d",&n , &m);
    for(int i = 0 ; i < n ; i++) {
        scanf("%d",&a[i]);
    }
    for(int i = 0 ; i <= n ; i++) {
        for(int j = 0 ; j <= m ; j++) {
            dp[i][j] = -5;
        }
    }

    while(maxValue*maxValue <= m) {
        maxValue++;
    }

    printf("%d",cost(n,m));
    



    return 0;
}