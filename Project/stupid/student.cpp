#include "student.h"
#include <cstring>
#include <stdio.h>
void printBin(int a[], int N);
void encode(int N, int M[]) {
  int array[N*8];
  memset(&array, 0 , sizeof(array));
  for(int i = 0 ; i < N ; i++) {
    for(int j = 0 ; j < 8 ; j++) {
      array[i*8+7-j] = M[i] & (1 << j) ? 1 : 0;
    }
  }
  int c1 = 0;
  int c0 = 0;
  for(int i = 0 ; i < N*8 ; i++) {
    if(array[i] == 1) c1++;
    else c0++;
  }
  // printBin(array,N);
  bool ONE = c1 < c0;
  // bool ONE = false;
  //encode meesage
  if(N <= 32) {
    for(int i = 0 ; i < N*8 ; i++) {
      if(array[i] == 1) send(i);
    }
  } else {
    for(int i = 0 ; i < N*8 ; i=i+2){
      int i1 = array[i];
      int i2 = array[i+1];
      if(i1 == 0 && i2 ==0) {
        if(ONE) {
          //don't send if ONE
        } else {
          send(i); send(i); send(i);
        }
      } else if(i1 == 0 && i2 == 1) {
        if(ONE) send(i);
        else {
          send(i); send(i);
        }
      } else if(i1 == 1 && i2 == 0) {
        if(ONE) {
          send(i); send(i);
        } else {
          send(i);
        }
      } else if(i1 == 1 && i2 == 1) {
        if(ONE) {
          send(i); send(i); send(i);
        } else {
          // don't send if !ONE
        }
      }
    }
    //send encode type at last index
    if(ONE) send(N*8);
  }
}

//------------------- DO NOT REMOVE NOR EDIT THESE 3 LINES -----------------
//------------------- above is encode, below is decode ---------------------
//--------------------cut here----------------------------------------------

void decode(int N, int L, int X[]) {
  int out[N*8+1];
  memset(&out,0,sizeof(out));
  //decode meesage
  if(N<=32) {
    for(int i = 0 ; i < L ; i++) {
      out[X[i]] = 1;
    }
  } else {
    for(int i = 0 ; i < L ; i++) {
      out[X[i]]++;
    }
    bool ONE = out[N*8] == 1;
    printf("ISONE %d\n",ONE);
    for(int i = 0 ; i < N*8 ; i=i+2) {
      int val = out[i];
      if(val == 0) {
        //do nothing if ONE
        if(ONE) {
          out[i] = 0; out[i+1] = 0;
        } else if(!ONE) {
          out[i] = 1; out[i+1] = 1;
        }
      } else if(val == 1) {
        if(ONE) {
          //0 1
          out[i] = 0; out[i+1] = 1;
        } else {
          //1 0
          out[i] = 1; out[i+1] = 0;
        }
      } else if(val == 2) {
        if(ONE) {
          //1 0
          out[i] = 1; out[i+1] = 0;
        } else {
          //0 1
          out[i] = 0; out[i+1] = 1;
        }
      } else if(val == 3) {
        if(ONE) {
          out[i] = 1; out[i+1] = 1;
        } else {
          out[i] = 0; out[i+1] = 0;
        }

      }
    }
  }
  // printBin(out,N);
  //print output
  for(int i = 0 ; i < N ; i++) {
    int dec = 0;
    for(int j = 0 ; j < 8 ; j++) {
      dec = dec << 1 | out[i*8+j];
    }
    // printf("%d ",dec);
    output(dec);
  }
  // printf("\n");

}

void printBin(int a[], int N) {
  for(int i = 0 ; i < N*8 ; i++) {
    printf("%d ",a[i]);
  }
  printf("\n");
}
