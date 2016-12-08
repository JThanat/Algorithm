#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace  std;

double v[100005];
double w[100005];
pair<double,int> r[100005];

int main() {
    int n;
    double weight,t;

    scanf("%lf %d",&weight, &n);
    for(int i = 0 ; i < n ; i++) {
        scanf("%lf",&v[i]);
    }

    for(int i = 0 ; i < n ; i++) {
        scanf("%lf",&t);
        w[i] = t;
        r[i] = make_pair(v[i]/t,i);
    }
    
    sort(r , r + n);
    double ans = 0,vi = 0 , sumW = 0;
    
    for(int i = n-1 ; i >= 0 ; i--) {
        int idx = r[i].second;
        if(weight - sumW > w[idx]) {
            ans += v[idx];
            sumW += w[idx];
        } else {
            ans += (weight - sumW)*v[idx]/w[idx];
            break;
        }

    }

    printf("%.4lf",ans);
    return 0; 
}