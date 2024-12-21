#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> ans(n);
    ans[0] = 1;
    for(int i = 0; i < n-1; i++){
        int c; cin >> c;
        ans[c+1] = i+2;
    }
    for(auto c : ans) cout << c << " ";
    return 0;
}             
