#include <stdio.h>
#include <vector>
using namespace std;
int T,N,E;
int u,v;
bool cycle;
void dfs(int v, vector<vector<int>> &g, vector<int> &col) {
    col[v] = 1; //gray
    for(int i = 0; i < g[v].size() ; i++) {
        if(col[g[v][i]] == 0) {
            dfs(g[v][i],g,col);
        } else if(col[g[v][i]] == 2) {
            cycle = true;
        }
    }
    col[v] = 2; //black

}
void hasCycle(vector<vector<int>> &g,vector<int> &col) {
    for(int i = 0 ; i < N ; i++) {
        if(col[i] == 0) {
             dfs(i,g,col);
        }
    }
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&N,&E);
        vector<vector<int>> g(N);
        vector<int> col(N);
        cycle = false;
        for(int j = 0 ; j < E ; j++) {
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        hasCycle(g,col);
        if(cycle) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
