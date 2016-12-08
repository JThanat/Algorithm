#include <stdio.h>

int inv = 0;
int a[100005];

void merge(int start , int mid , int end) {
    int i = start;
    int j = mid+1;
    int t[end-start+1];
    for(int k = 0 ; k < (end - start + 1) ; k++) {
        if(i > mid) {
            t[k] = a[j++];
            continue;
        }
        if(j > end) {
            t[k] = a[i++]; 
            continue;
        }
        if(a[i] <= a[j]) {
            t[k] = a[i++];
        } else {
            // if a[i] > a[j] then t[k] = a[j++] and inversion count = (from i to mid) 
            t[k] = a[j++];
            inv += mid - i + 1;
        }
    }
    for(int k = start,l=0 ; k <= end ; k++,l++) {
        a[k] = t[l];
    }
}

void divide(int start, int end) {
    if(start >= end) return;
    int mid = (start + end)/2;
    divide(start,mid);
    divide(mid+1,end);
    merge(start, mid ,end);
}



int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++) {
        scanf("%d",&a[i]);
    }
    divide(0,n-1);
    printf("%d",inv);

    return 0;   
}