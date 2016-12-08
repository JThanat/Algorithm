#include<stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int val;
    scanf("%d",&val);

    int a[8];
    memset(&a,0,sizeof(a));
    for(int i = 0 ; i < 8 ; i++) a[i] = 0;

    for(int i = 0 ; i < 8 ; i++) {
        a[7-i] = val & (1 << i)? 1 : 0;
    }

    for(int i = 0 ; i < 8  ;i++) {
        printf("%d",a[i]);
    }
    printf("\n");
    int dec = 0;
    for(int i = 0 ; i < 8 ; i++) {
        dec = dec << 1 | a[i];
    }
    printf("%d",dec);


}
