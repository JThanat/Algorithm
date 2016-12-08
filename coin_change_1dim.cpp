#include <stdio.h>
int coins[25];

int main() {
    int n,v;
    scanf("%d %d",&n, &v);
    for(int i = n ; i>0 ; i--) {
        scanf("%d",&coins[i]);
    }

    return 0;
}