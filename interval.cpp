#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int n,t;
    scanf("%d",&n);
    pair<int,int> s[n];
    for(int i = 0 ; i < n ; i++) {
        scanf("%d",&t);
        s[i] = make_pair(0,t);
    }
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&t);
        s[i].first = t;
    }
    sort(s,s+n);
    int ans = 1;
    int fin = s[0].first;
    for(int i = 1 ; i < n ;i++) {
        if(s[i].second >= fin) {
            ans++;
            fin = s[i].first;
        } 
    }
    printf("%d",ans);
    return 0; 
}