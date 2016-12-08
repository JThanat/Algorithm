#include "student.h"
#include <cstring>
void encode(int N, int M[]) {
  int array[N*8];
  memset(&array, 0 , sizeof(array));
  for(int i = 0 ; i < N ; i++) {
    for(int j = 0 ; j < 8 ; j++) {
      array[i*8+7-j] = M[i] & (1 << j) ? 1 : 0;
    }
  }

  for(int i = 0 ; i < N*8 ; i++) {
    if(array[i] == 1) send(i);
  }

}

//------------------- DO NOT REMOVE NOR EDIT THESE 3 LINES -----------------
//------------------- above is encode, below is decode ---------------------
//--------------------cut here----------------------------------------------

void decode(int N, int L, int X[]) {
  int out[N*8];
  memset(&out,0,sizeof(out));
  for(int i = 0 ; i < L ; i++) {
    out[X[i]] = 1;
  }

  for(int i = 0 ; i < N ; i++) {
    int dec = 0;
    for(int j = 0 ; j < 8 ; j++) {
      dec = dec << 1 | out[i*8+j];
    }
    output(dec);
  }
}
