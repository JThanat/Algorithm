#include <stdio.h>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int random_range(int left, int right) {
    int r = rand()*(1 << 16)%(right - left);
    return left + r;
}

void swap(vector<int> &d, int i, int j) {
    int tmp = d[i];
    d[i] = d[j];
    d[j] = tmp;
}

int partition(vector<int> &a,int left,int right){
    int pos = random_range(left,right);
    swap(a,left,pos);

    int p = a[left]; 
    int i = left;
    int j = right + 1;

    while(i < j) {
        while(a[--j] > p);
        while(a[++i] < p) { 
            if(i == right) break;
        }
        if(i < j) {
            swap(a,i,j);
        }
    }
    swap(a,left,j);

    return j;
    

}

int quickSelect(vector<int> &a, int left, int right, int kth) {
    // cout << "left " << left << " right " << right << endl;
    if(left == right) return a[left];
    int p = partition(a,left,right);
    int m = p - left + 1; // m is amount of data in left side of partition inclusive
    if(kth == m) return a[p];
    if(kth < m) {
        return quickSelect(a,left,p,kth);
    } else {
        return quickSelect(a,p+1,right,kth - m);
    }

}

int findMedIndex(vector<int> &a,int left, int right) {
    int med = (right - left)/2 + 1;
    int val = quickSelect(a,left,right,med);
    for(int i = left ; i <= right ; i++) {
        if(val == a[i]) return i;
    }
}

int mm5(vector<int> &a,int left, int right) {
    // implement using mm5
    int n = (right - left)/5;
    vector<int> medians;

    for(int i = 0; i < a.size()-1 ; i = i+5) {
        int l = i;
        int r = (i + 4) > right ? right : i+4;
        medians.push_back(a[findMedIndex(a,l,r)]);
    }
    
    return findMedIndex(medians,0,medians.size() - 1);
}
void printVector(vector<int> &a) {
    for(int i = 0 ; i < a.size() ; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
int quickSortPartition(vector<int> &a,int left,int right){
    int pos = random_range(left,right);
    swap(a,left,pos);
    
    int p = a[left]; 
    int i = left;
    int j = right + 1;

    while(i < j) {
        while(a[--j] > p);
        while(a[++i] < p) { 
            if(i == right) break;
        }
        if(i < j) {
            swap(a,i,j);
        }
    }
    swap(a,left,j);

    return j;
    

}
void quickSort(vector<int> &a, int left, int right) {
    if(left >= right) return;
    int p = quickSortPartition(a,left,right);
    quickSort(a,left,p-1); // sort left
    quickSort(a,p+1,right); //sort right
}

void findpair(vector<int> &a, int val) {
    int left = 0;
    int right = a.size()-1;
    while(left < right) {
        int sum = a[left] + a[right];
        if(val > sum) left++;
        else if(val < sum) right--;
        else {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}

int main(){
    int n,m;
    scanf("%d %d",&n, &m);
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) {
        scanf("%d", &v[i]);
    }
   //quickSort(v,0,n-1);
   sort(v.begin(),v.end());

   for(int i = 0; i < m ;i++) {
       int expected;
       scanf("%d", &expected);
       findpair(v,expected);
   }
   
    return 0;
}