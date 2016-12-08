#include <stdio.h>
int a[100010];
int n;
int search(int start , int end ,int val) {
    if(start > end) return end;
    int mid = (start + end)/2;
    if(a[mid] < val) {
        return search(mid+1,end,val);
    } else if(a[mid] > val){
        return search(start,mid-1,val);
    } else {
        int index = mid;
        int maxIndex = search(mid+1,n-1,val);
        if(a[index] == a[maxIndex]) return maxIndex;
    }

}

int main() {
    int m,t;
    scanf("%d %d",&n,&m);
    for(int i = 0 ; i < n ; i++) {
        scanf("%d",&a[i]);
    }
    for(int i = 0 ; i < m ; i++) {
        //query
        scanf("%d",&t);
        // int index = search(0,n-1,t);
        int l = 0 , r = n;
        while(l < r) {
            int m = (l+r)/2;
            if(t < a[m]) r = m;
            else l = m+1;
        }
        printf("%d\n",r-1);
    }
    return 0;
}