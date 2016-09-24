#include <stdio.h>
#include <vector>
using namespace std;

const int TYPE_A = 0; //type 0 tile empty at x y
const int TYPE_B = 1; //type 1 tile empty at x+1 y
const int TYPE_C = 2; //type 2 tile empty at x y+1
const int TYPE_D = 3; //type 3 tile empty at x+1 y+1

struct Tile {
    int type,x,y;
    Tile(int a , int b ,int c) {
        type = a;
        x = b;
        y = c;
    }
};
vector<Tile> tiles;
int checktype(int startx , int starty , int ex , int ey) {
    if(startx == ex && starty == ey) return TYPE_A;
    else if(startx + 1 == ex && starty == ey) return TYPE_B;
    else if(startx == ex && starty + 1 == ey) return TYPE_C;
    else if(startx + 1 == ex && starty + 1 == ey) return TYPE_D;
}
bool isInQuarter(int startx, int starty , int endx , int endy , int x , int y) {
    if(x >= startx && x <= endx && y >= starty && y <= endy) return true;
    return false;
}
void tiling(int startx , int starty , int endx ,int endy, int ex, int ey ) {
    int length = endx - startx + 1;
    if(length == 2) {
        int type = checktype(startx,starty,ex,ey);
        tiles.push_back(Tile(type,startx,starty));
        // printf("%d %d %d\n",type,startx,starty);
    } else {
        int midx = (startx + endx)/2;
        int midy = (starty + endy)/2;
        //Q1
        
        if(isInQuarter(midx + 1,starty,endx,midy,ex,ey)) {
            tiling(midx + 1 , starty , endx, midy, ex ,ey);
            tiles.push_back(Tile(TYPE_B,midx,midy));
            // printf("%d %d %d\n",TYPE_B,midx,midy);
        } else {
            tiling(midx + 1 , starty , endx, midy, midx+1 ,midy);
        }
        //Q2
        if(isInQuarter(startx , starty , midx,midy,ex,ey)) {
            tiling(startx,starty,midx,midy,ex,ey);
            tiles.push_back(Tile(TYPE_A,midx,midy));
            // printf("%d %d %d\n",TYPE_A,midx,midy);
        } else {
            tiling(startx,starty,midx,midy,midx,midy);
        }
        //Q3
        if(isInQuarter(startx , midy+ 1 , midx ,endy,ex,ey)) {
            tiling(startx,midy+1,midx,endy,ex,ey);
            tiles.push_back(Tile(TYPE_C,midx,midy));
            // printf("%d %d %d\n",TYPE_C,midx,midy);
        } else {
            tiling(startx,midy+1,midx,endy,midx,midy+1);
        }
        //Q4
        if(isInQuarter(midx + 1 , midy + 1, endx , endy ,ex,ey)) {
            tiling(midx+1,midy+1,endx,endy,ex,ey);
            tiles.push_back(Tile(TYPE_D,midx,midy));
            // printf("%d %d %d\n",TYPE_C,midx,midy);
        } else {
            tiling(midx+1,midy+1,endx,endy,midx+1,midy+1);
        }
        
        
    }
}

int main() {
    int L,x,y;
    scanf("%d %d %d",&L,&x,&y);
    tiling(0,0,L-1,L-1,x,y);
    printf("%d\n",tiles.size());
    for(int i = 0 ; i < tiles.size() ; i++) {
        printf("%d %d %d\n",tiles[i].type , tiles[i].x ,tiles[i].y);
    }
    return 0;
}