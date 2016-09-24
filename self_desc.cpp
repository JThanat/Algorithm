#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;
int g[700000];

int searchValue(int start , int end ,int n) {
    if(start > end) return start;
    int mid = (start+end)/2;
    if(g[mid] < n) {
        return searchValue(mid+1 ,end ,n);
    } else {
        return searchValue(start,mid-1,n);
    }
}

int main()
{
    int N,a,lastIndex;
    scanf("%d",&N);
    g[1] = 1;
    g[2] = 3;
    for(int i = 3, j = 2 ; ; i++) {
        if(i > g[j]) j++;
        g[i] = g[i-1] + j;
        if(g[i] > 2000000001) {
            lastIndex = i;
            break;
        }
    }
    for(int i = 0 ; i < N ; i++) {
        scanf("%d",&a);
        printf("%d\n",searchValue(1,lastIndex,a));
        // printf("%d\n",g[a]);
    }
       
     
    return 0;
}