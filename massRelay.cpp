#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int,int> PI;
typedef pair<int,PI> PII;

int  N,M,Q,D;
vector<PII> g;
int ans[5005];
int p[5005]; //parent node for joining group

int parent(int a) {
//    function Find(x)
//     if x.parent != x
//        x.parent := Find(x.parent)
//     return x.parent
    if(p[a] == a) return a;
    return p[a] = parent(p[a]);
}

void union_set(int a, int b) {
    // a.root parent = parent of
    p[parent(a)] = p[parent(b)];
}

int main(){
    scanf("%d %d %d",&N,&M,&Q);
    int n = N;
    for(int i = 0 ; i < M ; i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        g.push_back(make_pair(c,make_pair(a,b)));
    }
    sort(g.begin(),g.end());
    for(int i = 0 ; i < N  ; i++) p[i] = i;
    for(int i = 0 ; i < M ; i++) {
        int u = g[i].second.first;
        int v = g[i].second.second;
        int w = g[i].first;
        if(parent(u) != parent(v)) {
            union_set(u,v);
            ans[--n] = w;
        }
    }

    for(int i = 0 ; i < Q ; i++) {
        scanf("%d",&D);
        printf("%d\n",ans[D]);
    }
    return 0;
}
