#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
vector<vector<int>> g(1005);
vector<int> col(1005);
//stack<int> s;
// In this problem the graph point from a subject to prerequisite subject.
// So the destination of searching will be the first subject to be study.

void tSort(int v) {
    col[v] = 1; //gray
    for(int i = 1; i <= g[v][0] ; i++) {
        if(col[g[v][i]] == 0) { //minus one because the vertex start from
            tSort(g[v][i]);
        }
    }
    printf("%d ",v);
    col[v] = 2; // black
}

int main() {
    int n,m;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++) {
        scanf("%d",&m);
        vector<int> l(m+1);
        l[0] = m;
        for(int j = 1 ; j < m+1 ; j++) {
            scanf("%d",&l[j]);
        }
        g[i] = l;
    }
    //Tsort
    for(int i = 0 ; i < n ; i++) {
        if(col[i] == 0) {
            //isNotVisited
            tSort(i);
        }
    }
    return 0;
}
