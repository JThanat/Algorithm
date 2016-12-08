#include <stdio.h>
int v[(1 << 18) + 10];
int a[(1 << 18) + 10];

void hana(int* pv, int n) {
    if(n == 1) {
        printf("%d ",pv[0]);
    } else {
        int hn = n/2;
        for(int i = 0 ; i < hn ; i++) {
            int t = pv[i];
            pv[i] = pv[i] + pv[i+hn];
            pv[i+hn] = t - pv[i+hn];
        }
        hana(pv,hn);
        hana(pv+hn,hn);
    }
}

int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++) {
        scanf("%d",&v[i]);
    }
    hana(v,n);
}