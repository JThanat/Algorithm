#include <stdio.h>
#include <vector>

using namespace std;

const int MAX_SIZE = 30;
int g[MAX_SIZE];

int upperbound(int start , int end, int val) {
    if(start > end) return start;
    int mid = (start + end)/2;
    if(g[mid] < val) {
        return upperbound(mid+1,end,val);
    } else {
        return upperbound(start,mid-1,val);
    }
}

void gaa(int curIndex, int val) {
    if(curIndex == 0) {
        if(val == 1) printf("g");
        else printf("a");
        return;
    }
    int lo = g[curIndex - 1];
    int midSec = lo+curIndex+3;
    if(val <= lo) {
        return gaa(curIndex -1 , val);
    } else if(val > midSec) {
        return gaa(curIndex-1,val - midSec);
    } else if(val > lo && val <= midSec) {
        if(val - lo == 1) printf("g");
        else printf("a");
        return;
    }
    
}

int main() {
    int N,lastIndex;
    scanf("%d",&N);
    g[0] = 3;
    for(int i = 1 ; ; i++) {
         g[i] =  2*g[i-1] + i+3;
         if(g[i] > 1000000000) {
             lastIndex = i;
             break;
        }
    }
    int upperIndex = upperbound(0,lastIndex,N);
    gaa(upperIndex,N);
    
    
    
    return 0;
}