#include <stdio.h>

char m[1005][1005];
int M[1005][1005];

int min(int a, int b) {
    return a < b ? a : b;
}
int main() {
    int r,c;
    scanf("%d %d",&r,&c);
    for(int i = 1 ; i <= r ; i++) {
        scanf("%s",m[i]);
    }
    int ans = 0;
    for(int i = 1 ; i <= r ;i++) {
        for(int j = 1 ; j <= c ;j++) {
            if(m[i][j] == '1') {
                M[i][j] = min(min(M[i-1][j],M[i][j-1]),M[i-1][j-1]) + 1;
                if(M[i][j] > ans) ans = M[i][j];
            }
        }
    }
    printf("%d", ans);
    return 0;
}