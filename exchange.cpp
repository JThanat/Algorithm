#include <stdio.h>

int K,N;
double g[505][505];

int main() {
    scanf("%d",&K);
    while(K--) {
        scanf("%d",&N);
        for(int j = 0 ; j < N ; j++) {
            for(int i = 0 ; i < N ; i++) {
                scanf("%lf",&g[i][j]);
            }
        }
        //do floyd-warshall!!





    }

}
