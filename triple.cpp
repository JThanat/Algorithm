#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1000];
int n,m;
bool pairSum(int val, int start) {
    int i = start , j = n-1;
    while (i < j) {
        int sum = a[i] + a[j];
        if(sum > val) {
            j--;
        } else if(sum < val) {
            i++;
        } else {
            return true;
        }
    }
    return false;
}
void tripleSum(int val) {
    int findVal;
    bool found = false;
    for(int j =  0 ; j < n ; j++) {
        findVal = val - a[j];
        found = pairSum(findVal,j+1);
        if(found) break;
        
    }
    if(found) printf("YES\n");
    else printf("NO\n");


}
int main() {
    scanf("%d %d",&n,&m);
    for(int i = 0 ; i < n ; i++) {
        scanf("%d",&a[i]);
    }
    sort(a,a + n);
    
    int val;
    for(int i = 0 ; i < m ; i++) {
        scanf("%d",&val);
        tripleSum(val);
    }
    return 0;
}