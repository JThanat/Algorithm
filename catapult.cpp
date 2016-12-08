#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
vector<vector<int>> g(1005);
vector<vector<int>> gt(1005);
vector<int> c(1005);
vector<int> ct(1005);
stack<int> s;

int dfs(int u) {
    c[u] = 1; //gray
    int res = 0;
    for(int i = 1 ; i <= g[u][0] ; i++) {
        if(c[g[u][i]] == 0) {
            res += dfs(g[u][i]);
        }
    }
    c[u] = 2;
    return 1 + res;
}

void scc(int u) {
    ct[u] = 1;
    for(int i = 1 ; i <= gt[u][0] ; i++) {
        if(ct[gt[u][i]] == 0) {
            scc(gt[u][i]);
        }
    }
    ct[u] = 2;
    s.push(u);
}


int main(){
    int n,m;
    scanf("%d",&n);
    //read input
    for(int i = 0 ; i < n ; i++) {
        scanf("%d",&m);
        vector<int> l(m+1);
        l[0] = m;
        for(int j = 1 ; j <= m ; j++) {
            scanf("%d",&l[j]);
        }
        g[i] = l;
        //init gt
        vector<int> v(1);
        gt[i] = v;
    }
    //create GT
    for(int i = 0 ; i < n ;i++) {
        for(int j = 1 ; j <= g[i][0] ; j++) {
            gt[g[i][j]].push_back(i);
        }
    }
    for(int i = 0 ; i < n ; i++) {
        gt[i][0] = gt[i].size() - 1;
    }
    // finish creating Gt

    for(int i = 0 ; i < n ; i++) {
        if(ct[i] == 0) {
            scc(i);
        }
    }
    priority_queue<int,vector<int>,greater<int>> ans;
    while(!s.empty()) {
        int u = s.top();
        if(c[u] == 0) {
            int res = dfs(u);
            ans.push(res);
        }
        s.pop();
    }

    while(!ans.empty()) {
        printf("%d ",ans.top());
        ans.pop();
    }
    return 0;
}
