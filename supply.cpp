#include <stdio.h>
#include <queue>
#include <map>
#include <vector>

using namespace std;
vector<pair<int,int>> days(200005);

int main() {
    int n,m,k,d,e,l;
    queue<int> requests,plants;
    
    scanf("%d %d %d",&n,&m,&k);

    
    for(int i = 0 ; i < k ; i++) {
        scanf("%d %d %d",&d,&e,&l);
        days[d] = make_pair(e,l);
    }
    for(int i = 1 ; i <= k ; i++) {
        e = days[i].first;
        l = days[i].second;
        if(e == 0) {
            // produce
            if(!requests.empty()) {
                printf("%d\n",requests.front());
                requests.pop();
            } else {
                printf("0\n");
                plants.push(l);
            }
            
        } else if(e == 1) {
            // request
            if(!plants.empty()) {
                printf("%d\n",plants.front());
                plants.pop();
            } else {
                printf("0\n");
                requests.push(l);
            }
        }
    }

    return 0;
}