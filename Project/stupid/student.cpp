#include "student.h"
#include <cstring>
#include <stdio.h>
void printBin(int a[], int N);
void encode(int N, int M[]) {
  int a[N*8];
  memset(&a, 0 , sizeof(a));
  for(int i = 0 ; i < N ; i++) {
    for(int j = 0 ; j < 8 ; j++) {
      a[i*8+7-j] = M[i] & (1 << j) ? 1 : 0;
    }
  }
  int c1, c0;
  c1 = c0 = 0;
  for(int i = 0 ; i < N*8 ; i++) {
    if(a[i] == 0) c0++;
    else if(a[i] == 1) c1++;
  }
  bool ONE = c1 < c0;
  for(int i = 0 ; i < N*8 ; i = i+2) {
    int i1 = a[i];
    int i2 = a[i+1];
    if(i1 == 0 && i2 == 0) {
      if(ONE) {
        //don't send
      } else {
        send(i/2); send(i/2); send(i/2);
      }
    } else if(i1 == 0 && i2 == 1) {
      if(ONE) {
        send(i/2);
      } else {
        send(i/2); send(i/2);
      }
    } else if(i1 == 1 && i2 == 0) {
      if(ONE) {
        send(i/2); send(i/2);
      } else {
        send(i/2);
      }
    } else if(i1 == 1 && i2 == 1) {
      if(ONE) {
        send(i/2); send(i/2); send(i/2);
      } else {
        //don't send
      }
    } 
  }
  if(ONE) {
    for(int i = 0 ; i < 5 ; i++) send(0);
  }
}

//------------------- DO NOT REMOVE NOR EDIT THESE 3 LINES -----------------
//------------------- above is encode, below is decode ---------------------
//--------------------cut here----------------------------------------------

void decode(int N, int L, int X[]) {
  int a[N*8];
  int out[N*8];
  memset(&a,0,sizeof(a));
  memset(&out,0,sizeof(out));

  for(int i = 0 ; i < L ; i++) {
    a[X[i]*2]++;
  }
  bool ONE = false;
  if(a[0] >= 5) {
    ONE = true;
    a[0] -= 5;
  }
  for(int i = 0 ; i < N*8 ; i = i+2) {
    int val = a[i];
    if(val == 0) {
      if(ONE) {
        // do nothing
        out[i] = 0;
        out[i+1] = 0;
      } else { 
        out[i] = 1;
        out[i+1] = 1;
      }
    } else if(val == 1) {
      if(ONE) {
        out[i] = 0;
        out[i+1] = 1;
       } else {
        out[i] = 1;
        out[i+1] = 0;
      }
    } else if(val == 2) {
      if(ONE) {
        out[i] = 1;
        out[i+1] = 0;
      } else {  
        out[i] = 0;
        out[i+1] = 1;
      }
    } else if(val == 3) {
      if(ONE) {
        out[i] = 1;
        out[i+1] = 1;
      } else {
        out[i] = 0;
        out[i+1] = 0;
      }
    } else {
      //impossible
    }
  }
  
  for(int i = 0 ; i < N ; i++) {
    int dec = 0;
    for(int j = 0 ; j < 8 ; j++) {
      dec = (dec*2) + out[i*8+j];
    }
    output(dec);
  }

}

void printBin(int a[], int N) {
  for(int i = 0 ; i < N*8 ; i++) {
    printf("%d ",a[i]);
  }
  printf("\n");
}
