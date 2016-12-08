#include <stdio.h>
int a[105][105];
int sum[105][105];

int max(int a, int b) {
    return a > b ? a : b;
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j <= i ;j++) {
            scanf("%d",&a[i][j]);
            if(i == 0 && j==0) sum[i][j] = a[i][j];
            else if(j == 0) sum[i][j] = sum[i-1][j] + a[i][j];
            else if(j == i) sum[i][j] = sum[i-1][j-1] + a[i][j];
            else {
                sum[i][j] = max(sum[i-1][j-1] + a[i][j],sum[i-1][j] + a[i][j]);
            }
        }
    }
    
    int ans = sum[n-1][0];
    for(int i = 0 ; i < n ; i++) {
        ans = max(ans,sum[n-1][i]);
    }
    printf("%d",ans);

    
    return 0;
}