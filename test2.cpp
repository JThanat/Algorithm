#include <stdio.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

int main() {
    int x,y;
    scanf("%d %d",&x,&y);
    srand(y);
    for(int i = 0 ; i < x ; i++) {
        printf("%d ",rand()%255);
    }


}
