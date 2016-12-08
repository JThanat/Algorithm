#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &a, int x, int left, int right)
{
    if(left >= right) {
        if(pos == 0) return -1;
        else if(pos == a.size()-1) return a[pos];
    }
    int pos = (left + right)/2;
    if(x == a[pos]) return a[pos];
    if(x > a[pos] && x < a[pos + 1]) return a[pos];
    if(x < a[pos]){
        return  binary_search(a,x,left,pos); // serch left
    } else {
        return  binary_search(a,x,pos+1,right); //search right
    }

    
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int left = 0;
    int right = n - 1;
    for(int i = 0 ; i < m; i++) {
        int x;
        scanf("%d", &x);
        int ans = binary_search(a,x,left,right);
        printf("%d \n",ans);
        
    }
    return 0;
}
