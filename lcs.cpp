#include <stdio.h>
#include <string.h>

using namespace std;

char a[505],b[505];
int mem[505][505];

int max(int x, int y) {
    return x > y ? x : y;
}

int lcs(int i, int j) {
    if(i < 0 || j < 0) return 0;
    if(mem[i][j] > 0) return mem[i][j];
    
    if(a[i] == b[j]) return 1 + lcs(i-1,j-1);
    else {
        return mem[i][j] = max(lcs(i-1,j),lcs(i,j-1));
    }
}

int main() {
    scanf("%s %s",a,b);
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int ans = lcs(i,j);
    printf("%d",ans);

}