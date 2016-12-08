#include <stdio.h>
int N,M,K;
int mem[35][35][35];
int f(int n,int m , int k) {
    if(n < 0) return 0;
    if(mem[n][m][k] != -1) return mem[n][m][k];
    if(n == 0 && m <= M && k == 0) {
        return mem[n][m][k] = 1;
    } 
    if(m > M && n != 0) return mem[n][m][k] = 0;
    if(k < 0 && n != 0) return mem[n][m][k] = 0;
    return mem[n][m][k] = f(n-1,m+1,k) + f(n-1,1,k-1);  
}

int main() {
    scanf("%d %d %d",&N,&M,&K);
    for(int i = 0 ; i < 35 ; i++) {
        for(int j = 0 ; j < 35 ; j++) {
            for(int k = 0 ; k < 35 ; k++) {
                mem[i][j][k] = -1;
            }
        }
    }
    printf("%d",f(N-1,1,K));
    return 0;
}   