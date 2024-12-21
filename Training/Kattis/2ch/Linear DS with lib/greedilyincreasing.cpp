#include<bits/stdc++.h>

using namespace std;
// #define int long long int
// #define all(a) a.begin(), a.end()

signed main(){
    int n; cin >> n;
    int p; cin >> p;
    vector<int> ans;
    ans.push_back(p);
    for(int i = 1; i < n; i++){
        int c; cin >> c;
        if (c > p){
            ans.push_back(c);
            p = c;
        }
    }
    cout << ans.size() << endl;
    for(auto c : ans){
        cout << c << " ";
    }
    return 0;
}