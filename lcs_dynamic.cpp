#include <stdio.h>
#include <string.h>

char a[505],b[505];
int mem[505][505];
char res[505];

int max(int x, int y) {
    return x > y ? x : y;
}

int main() {
    scanf("%s %s",a,b);
    int n = strlen(a);
    int m = strlen(b);
    for(int i = 1; i <= n ; i++) {
        for(int j = 1 ; j <= m ; j++) {
            if(a[i-1] == b[j-1]) {
                mem[i][j] = mem[i-1][j-1] + 1;
            } else {
                mem[i][j] = max(mem[i-1][j] , mem[i][j-1]);
            }
            
        }
        
    }
    // for(int i = 0 ; i <= n ;i++) {
    //     for(int j = 0 ; j <= m ; j++) {
    //         printf("%d ",mem[i][j]);
    //     }
    //     printf("\n");
    // }
    int k = 0;
    int i = n, j = m;
    while(i > 0 && j > 0) {
        if(a[i-1] == b[j-1]) {
            res[k] = a[i-1];
            j--;
            i--;
            k++;
        } else if(mem[i-1][j] > mem[i][j-1]) {
            //move left
            i--;
        } else {
            //move up
            j--;
        }
    }
    for(k = k-1 ; k >=0 ; k--) {
        printf("%c",res[k]);
    }

    printf("\n%d",mem[n][m]);

}