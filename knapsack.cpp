#include <stdio.h>
float val[1000];
float weight[1000];
float mem[1000][1000];

float max(float a , float b) {
    return a > b ? a : b;
}
float choose(int i, float w) {
    if(w == 0 || i < 0) return 0.0f;
    if(w < weight[i]) return choose(i-1,w);
    else {
        return max( val[i] + choose(i-1,w-weight[i]), choose(i-1,w)); 
    }
}

int main() {
    int n;
    float maxW;
    scanf("%d %f",&n, &maxW);
    for(int i = 0 ; i < n ; i++) {
        scanf("%f",&val[i]);
    }
    for(int i = 0 ; i < n ; i++) {
        scanf("%f",&weight[i]);
    }
    printf("%f",choose(n-1,maxW));
    return 0;
}