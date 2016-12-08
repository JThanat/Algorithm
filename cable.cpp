#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

typedef pair<int,int> pairInt;
int cost[1005][1005];
int mst[1005];
int d[1005];
int p[1005];

bool lessThan(int a , int b) {
    if(a < 0) return false;
    else if(b < 0) return true;
    return a < b ? true : false;
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n-1 ; i++) {
        for(int j = 0 ; j < n-i-1 ; j++) {
            int t;
            scanf("%d",&t);
            cost[i][i+j+1] = t;
            cost[i+j+1][i] = t;
        }
    }
    for(int i = 0 ; i < n  ;i++) {
        d[i] = p[i] = -1;
    }
    mst[0] = 1;
    d[0] = 0;
    int sum = 0;
    for(int i = 0 ; i < n ; i++) {
        //find min u
        int u = 0;
        for(int i = 0 ; i < n ; i++) {
            if(lessThan(d[i],d[u])) u = i;
        }
        //printf("choose vertex %d\n",u);
        sum += d[u]; //add minimum value into our output
        d[u] = -1;
        mst[u] = 1; //add to our tree
        for(int v = 0 ; v < n ; v++) {
            //update value
            if(u == v) continue;
            if(mst[v] == 0 && lessThan(cost[u][v],d[v])) {
                d[v] = cost[u][v];
                p[u] = v;
            }
        }
    }
    printf("%d",sum);

    /*
    priority_queue<pairInt,vector<pairInt>, greater<pairInt>> pq;
    for(int i = 0 ; i < n-0-1 ; i++) {
        printf("Put vertex: %d with cost : %d \n",0+i+1,cost[0][i]);
        pq.push(make_pair(cost[0][i],0+i+1));
    }
    int sum = 0;
    while(!pq.empty()) {
        pairInt p = pq.top();
        // printf("Top vertex : %d with cost : %d \n",p.second,p.first);
        if(mst[p.second] == 0) {
            // printf("choose : %d with cost : %d \n",p.second,p.first);
            sum += p.first;
            for(int i = 0 ; i < n-p.second-1 ; i++) {
                printf("Put vertex: %d with cost : %d \n",p.second+i+1,cost[p.second][i]);
                pq.push(make_pair(cost[p.second][i],p.second+i+1));
            }
            mst[p.second] = 1;
        }
        pq.pop();
    }
    printf("%d",sum);
    */
    return 0;
}
