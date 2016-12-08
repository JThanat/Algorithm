#include <stdio.h>
#include <vector>
#include <utility>
#define INF 2000000000

using namespace std;

typedef pair<int,int> IP;
vector<vector<IP>> e(105);
int d[105];
int n,edge,s;
bool neg() {
    for(int u = 0; u < n ; u++) {
        for(int j = 0; j < e[u].size() ; j++) {
            int v = e[u][j].first;
                int wuv = e[u][j].second;
                if(d[u] + wuv < d[v]) {
                    return true;
                }
        }
    }
    return false;
}
int main() {
    scanf("%d %d %d",&n, &edge,&s);
    int a,b,c;
    for(int i = 0 ; i < n ; i++) {
        d[i] = INF;
    }
    for(int i = 0 ; i < edge ; i++) {
        scanf("%d %d %d",&a,&b,&c);
        e[a].push_back(make_pair(b,c));
    }
    d[s] = 0;
    for(int i = 1 ; i < n ; i++) {
        for(int u = 0 ; u < n ; u++) {
            for(int j = 0 ; j < e[u].size() ; j++) {
                int v = e[u][j].first;
                int wuv = e[u][j].second;
                if(d[u] + wuv < d[v]) {
                    d[v] = d[u]+wuv;
                }
            }
        }
    }
    bool isNeg = neg();
    if(isNeg) {
        printf("-1");
    } else {
        for(int i = 0 ; i < n ; i++) {
            printf("%d ",d[i]);
        }
    }


    return 0;
}
