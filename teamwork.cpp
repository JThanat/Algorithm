#include <stdio.h>
#include <algorithm>

using namespace std;

long long w[105],s[105];
long long t[100005];

int main() {
    int n,m;
    scanf("%d %d",&n, &m);
    for(int i = 0 ; i < m ; i++) {
        scanf("%d",&t[i]);
    }
    sort(t,t+m);
    for(int i = 0 ; i < m ; i++) {
        w[i%n] += t[i];
        s[i%n] += w[i%n];
    }
    double sum  = 0;
    for(int i = 0 ; i < n ; i++) {
        sum += s[i];
    }
    printf("%.3lf",sum/(double)m);
    return 0; 
}