#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n <= 0) return 0;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int sum = v[0];
    int max = v[0];
    for (int i = 1; i < n; i++)
    {
        sum = v[i] > sum + v[i] ? v[i] : sum + v[i];
        if(max < sum) max = sum;
    }
    cout << max;
    return 0;
}