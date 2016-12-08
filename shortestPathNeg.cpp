#include <stdio.h>
#define MAX_NODE 100
#define INFINITY 999999

int d[105][105];
int w[105][105];
int n,e,s;

int min(int a, int b) {
    return a < b ? a : b;
}

bool checkNeg() {
    for(int u = 0 ; u < n ; u++) {
        for(int v = 0 ; v < n ; v++) {
            if(d[s][u] + w[u][v] < d[s][v])  return true;
        }
    }
    return false;
}
int main(){
    scanf("%d %d %d",&n,&e,&s);
    for(int i = 0 ; i < MAX_NODE + 5 ; i++) {
        for(int j = 0 ; j < MAX_NODE + 5 ; j++) {
            if(i == j) {d[i][j] = 0; w[i][j] = 0;}
            else {d[i][j] = INFINITY; w[i][j] = INFINITY;}
        }
    }
    for(int i = 0 ; i < e ; i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        d[a][b] = c;
        w[a][b] = c;
    }

    for(int k = 0 ; k < n ; k++) {
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(d[i][k] == INFINITY || d[k][j] == INFINITY) continue;
                d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
            }
        }
    }

    if(checkNeg()) {
        printf("-1\n");
    } else {
        for(int i = 0 ; i < n ; i++) {
            printf("%d ",d[s][i]);
        }
    }

    return 0;
}
