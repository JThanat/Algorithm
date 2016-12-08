#include <stdio.h>
int c[10005];
int ans[10005];

int max(int a , int b) {
    return a > b ? a : b;
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n ; i++) {
        scanf("%d",&c[i]);
        if(i == 1) ans[i] = c[i];
        ans[i] = max(ans[i-1] ,ans[i-2] + c[i]); //f(i) = max(f(i-2) + c[i], f(i-1))
    }
    printf("%d",ans[n]);
    return 0;
}