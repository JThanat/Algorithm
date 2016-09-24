    #include <stdio.h>

    int max(int a , int b) {
        return a > b ? a : b;
    }
    int min(int a , int b) {
        return a < b ? a : b;
    }
    int main() {
        int n,sumArr,sum1,sum2,max1,min1,tmp;
        scanf("%d",&n);
        scanf("%d",&tmp);
        sumArr = max1 = sum1 = sum2 = min1 = tmp;
        for(int i = 1 ; i < n ; i++) {
            scanf("%d",&tmp);
            // sumArr
            sumArr += tmp;
            // mcs
            sum1 = max(tmp,sum1 + tmp);
            max1 = max(max1, sum1);
            // min
            sum2 = min(tmp,sum2 + tmp);
            min1 = min(sum2,min1);
        }
        printf("%d\n", max(max1, sumArr == min1 ? max1 : sumArr - min1));
        
    }