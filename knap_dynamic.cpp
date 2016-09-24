#include <stdio.h>
#include<set>
int val[1000];
int weight[1000];
int v[1000][1000];

using namespace std;


int max(int a , int b) {
    return a > b ? a : b;
}

int main() {
    int n,w;
    scanf("%d %d",&n,&w);
    for(int i = 1 ; i <= n ; i++) {
        scanf("%d",&val[i]);
    }
    for(int i = 1 ; i <= n ; i++) {
        scanf("%d",&weight[i]);
    }
    for(int i = 1 ; i <= n ; i++) { // index of object
        for(int j = 1 ; j <= w ; j++) { // weight
            if(j < weight[i]) v[i][j] = v[i-1][j];
            else {
                v[i][j] = max(v[i-1][j] , val[i] +v[i-1][j-weight[i]]);
            }
        }
    }
    for(int i = 0 ; i <= n ; i++) { // index of object
        for(int j = 0 ; j <= w ; j++) { // weight
           printf("%d\t", v[i][j]);
        }
        printf("\n");
    }
    int i = n;
    int j = w;
    int ans[1000];
    int k = 0;
    set<int> s;
    while(i > 0 && j > 0) {
        int wi = weight[i];
        if(j < wi) {
            i--;
        } else if(v[i][j] == val[i] + v[i-1][j-wi]) {
            printf("vij : %d val[i] : %d v[i-1][j-wi] : %d\n",v[i][j] , val[i], v[i-1][j-wi]);
            s.insert(i);
            i--;
            j -= wi;
        } else {
            i--;
        }
    }
    printf("We choose: ");
    for(auto x : s) {
        printf("%d ",x);
    }
    printf("\n%d",v[n][w]);
    return 0;
}