#include <cstdio>

typedef long long llnt;

int d[1005];
int N;

bool pass(llnt v, llnt q) {
  llnt sum = N;
  for(int i=0; i<N; i++) sum += v / d[i];
  printf("Total Served %lld\n",sum);
  return sum >= q;
}

llnt calc(llnt q) {
  llnt start = 0;
  llnt end = 1000000000005;
  while(start <= end) {
    llnt mid = (start + end) / 2;
    if(pass(mid, q)) end = mid - 1;
    else start = mid + 1;
  }
  return start;
}

int main() {
  int A;
  scanf("%d%d",&N,&A);
  for(int i=0; i<N; i++) scanf("%d", d+i);
  while(A--) {
    llnt q; scanf("%lld", &q);
    printf("%lld\n", calc(q));
  }
}
