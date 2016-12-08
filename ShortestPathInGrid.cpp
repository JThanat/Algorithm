#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

char grid[105][105];
int visited[105][105];
int length[105][105];
int r,c;

int min(int a,int b){
    if(a < 0) return b;
    if (b < 0) return a;
    return a < b? a : b;
}

bool inGrid(int i , int j){
    return i >= 0 && i < r && j >=0 && j <c;
}

void go(queue<pair<int,int>> &q, int i , int j) {
    q.push(make_pair(i,j));
    visited[i][j] = 1;
}
int main() {
    scanf("%d %d",&r, &c);
    for(int i = 0 ; i < r ; i++) {
        scanf("%s",grid[i]);
    }
    for(int i =0 ; i< r ;i++) {
        for(int j = 0 ; j < c ;j++) {
            length[i][j] = -1;
        }
    }
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    visited[0][0] = 1;
    length[0][0] = 0;

    while(!q.empty()) {
        pair<int,int> current = q.front();
        int i = current.first;
        int j = current.second;
        visited[i][j] = 2;
        if(i == r-1 && j == c-1) break;
        if(grid[i][j] == '.') {
            if(inGrid(i+1,j) && visited[i+1][j] == 0){
                go(q,i+1,j);
                length[i+1][j] = min(length[i+1][j],length[i][j] + 1);
            }
            if(inGrid(i,j+1) && visited[i][j+1] == 0){
                go(q,i,j+1);
                length[i][j+1] = min(length[i][j+1],length[i][j] + 1);
            }
            if(inGrid(i-1,j) && visited[i-1][j] == 0){
                go(q,i-1,j);
                length[i-1][j] = min(length[i-1][j],length[i][j] + 1);
            }
            if(inGrid(i,j-1) && visited[i][j-1] == 0){
                go(q,i,j-1);
                length[i][j-1] = min(length[i][j-1],length[i][j] + 1);
            }
        }
        q.pop();
    }
    printf("%d",length[r-1][c-1]);




    return 0;
}
