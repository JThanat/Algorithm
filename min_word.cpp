#include <stdio.h>
#include <string>
#include <map>

using namespace std;

std::map<string,bool> dict;

int min(int a, int b) {
    if(a < 0) return b;
    else if(b < 0) return a;
    return a < b ? a : b;
}
int wordSep(string s) {
    int N[s.length() + 1];
    for(int i = 0 ; i < 1000 ; i++) {
        N[i] = -1;
    }
    N[0] = 0;
    for(int k = 2; k <= s.length() ; k++) {
        for(int i = 1 ; k < k ; i++) {
            string word = s.substring(i,k-i+1); // s[i..k]
            if(dict[word]) {
                if(N[i-1]+1 < N[k]) {
                    // save only min value 
                    N[k] = N[i-1] + 1
                }
            }
        }
    }
}

int main() {
    // to be implement later!! 
    return 0;
}