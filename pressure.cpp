#include <stdio.h>
int p[10005];
int a[10005];

int min(int a,int b) {
    if(a < 0) return b;
    else if(b < 0) return a;
    return a < b ? a : b;
}
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 0 ; i < n ; i++) {
        scanf("%d",&p[i]); 
        if(i <= k) a[i]  = p[i]; //first first element will occupy area till k+1 elements
    }
    for(int i = k + 1 ; i < n ; i++) {
        int lowerBound = i - 2*k -1 <  0 ? 0 : i - 2*k - 1;
        int minN = -1;
        for(int j = lowerBound ; j < i ; j++) {
            minN = min(minN, a[j]);
        }
        a[i] = minN  + p[i];
    }
    int ans = -1;
    // for(int i = 0; i < n ; i++){
    //     printf("%d ",a[i]);
    // }
    int backward = n-k-1 < 0 ? 0 : n-k-1;
    for(int i = n-1 ; i >= backward ; i--) {
        ans = min(ans,a[i]);
    }
    printf("%d",ans);
    
    return 0;
}