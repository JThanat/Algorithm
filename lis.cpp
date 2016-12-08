#include <stdio.h>
int c[1005];
int a[1005];

int max(int a , int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0 ; i < n ; i++) {
        scanf("%d",&a[i+1]);
    }
    a[0] = -1;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 0 ; j < i ; j++) {
            if(a[i] > a[j]) {
                c[i] = max(c[i],1+c[j]);
            }
        }
    }
    int max = c[0];
    for(int i = 0 ; i <= n ;i++) {
        if(c[i] > max) max = c[i];
    }
    printf("%d", max);

    return 0;
}
