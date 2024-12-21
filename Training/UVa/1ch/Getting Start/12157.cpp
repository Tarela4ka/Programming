#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, i, j;
    while(cin >> n >> i >> j){
        int ans = 0;
        for(;true;){
            ans++; 
            i = ceil((double)i/2); 
            j = ceil((double)j/2);
            if (i == j) break;
        }
        cout << ans << '\n';
    }
    return 0;
}