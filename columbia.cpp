#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#define INF 2000000000

using namespace std;
typedef pair<int,int> IP;
typedef pair<int,IP> IIP;

int r,c;

bool isInTable(int i,int j) {
    return i < r && j < c && i >= 0 && j >= 0;
}

int main() {
    int dir[4][2] = {1,0,0,1,-1,0,0,-1};
    scanf("%d %d",&r,&c);
    int g[r][c];
    int path[r][c];
    for(int i =0 ; i < r ; i++) {
        for(int j =0 ; j < c ;j++) {
            scanf("%d",&g[i][j]);
            path[i][j] = INF;
        }
    }

//    priority_queue<IIP, vector<IIP>,less<IIP>> pq;
    priority_queue< pair< int , pair<int,int> > > pq;
    path[0][0] = 0;
    pq.push(make_pair(0,make_pair(0,0))); //initial distance --> sort by distance from current path
    int round = 0;
    while(!pq.empty()) {
        int curDist = -pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();
        for(int k = 0; k < 4 ; k++) { //adjacent to the node
            int du = u + dir[k][0];
            int dv = v + dir[k][1];
            if(du >= r || dv >= c || du < 0 || dv < 0) continue;
            if(path[du][dv] != INF && path[du][dv] <= curDist + g[du][dv]) continue;
            path[du][dv] = curDist + g[du][dv];
            pq.push(make_pair(-(curDist + g[du][dv]), make_pair(du,dv)));
        }
        round++;
    }
    for(int i = 0 ; i < r ; i++) {
        for(int j = 0 ; j < c ;  j++) {
            printf("%d ",path[i][j]);
        }
        printf("\n");
    }
//    printf("%d ",round);
    return 0;
}
