#include<stdio.h>
#include<vector>

using namespace std;

typedef long long llint;

llint checkServeTime(llint spentTime,vector<llint> chefs) {
    llint totalServed = chefs.size();
    
    for(int i = 0 ; i < chefs.size() ;i++) {
        totalServed += spentTime / chefs[i];
    }
    return totalServed;
}
llint serveAt(llint start , llint end , llint cus, vector<llint> chefs) {
    if(start > end) return start;
    llint mid = (start + end)/2;
    llint served = checkServeTime(mid,chefs);
    // printf("served : %lld start : %lld end:  %lld mid : %lld \n",served,start,end,mid);
    if(served < cus) {
        return serveAt(mid+1,end,cus,chefs);
    } else {
        return serveAt(start,mid-1,cus,chefs);
    }
}

int main(){
    llint n;
    int a;
    scanf("%lld %d",&n,&a);
    
    vector<llint> chefs(n);

    for(int i = 0; i < n ; i++) {
        scanf("%d",&chefs[i]);
    }
    for(int i = 0 ; i < a ; i++) {
        llint cus;
        scanf("%lld",&cus);
        
        llint maxTime = cus * chefs[0];
        
        llint res = serveAt(0,maxTime,cus,chefs);
        printf("%lld\n",res);
    }

    return 0;
}