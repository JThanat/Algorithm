#include <stdio.h>

using namespace std;

int a[100005];
int main() {
    int N;
    scanf("%d",&N);
    for(int i = 0 ;  i < N ; i++) {
        scanf("%d",&a[i]);
    }
    //Non wrapping
    int sum1 = a[0];
    int max1 = a[0];
    for(int i = 1 ; i < N ; i++) {
        sum1 = sum1 + a[i] < a[i] ? a[i] : sum1 + a[i];
        if(sum1 > max1) max1 = sum1;
    }
    //For wrapping
    int sum2 = 0;
    int min2 = 0;
    int sumArr = 0;
    for(int i = 0 ; i < N ; i++) {
        sum2 = sum2 + a[i] < 0 ? sum2 + a[i] : 0;
        if(sum2 < min2) min2 = min2 = sum2;
        sumArr += a[i];
    }

    int wrapSum = sumArr - min2;
    if(max1 < 0) {
        printf("%d",max1);
        return 0;
    }
    max1 > wrapSum ? printf("%d",max1) : printf("%d",wrapSum);
    return 0;
}