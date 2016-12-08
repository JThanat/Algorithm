#include <stdio.h>
#include <vector>

using namespace std;

vector<int> g[1005];
int col[1005];
int N,E,K;
int c,ans;

void dfs(int v, int x) {
    if(x > K) return;
    if(col[v] == 0) c++;
    col[v] = 1; //gray
    for(int i = 0 ; i < g[v].size() ; i++) {
        dfs(g[v][i],x+1);
    }
    col[v] = 2;//black
}

int main() {
    scanf("%d %d %d",&N,&E,&K);
    for(int i = 0 ; i < E ; i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans = 0;
    for(int i = 0; i < N ;i++) {
        for(int j = 0; j < N ; j++) col[j] = 0;
        c = 0;
        dfs(i,0);
        ans = c > ans ? c : ans;
    }
    printf("%d",ans);
    return 0;
}

