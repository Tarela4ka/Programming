#include<bits/stdc++.h>

using namespace std;
// #define int long long int
// #define all(a) a.begin(), a.end()

unordered_map<int, vector<int>> r;
vector<int> a;
vector<int> vis;

void ref(int numb, int ind){
    if (ind == 0) return;
    ind--;
    vis[ind] = 1;
    for(auto c : r[numb-1]){
        c--;
        if (c > ind && !vis[c]){
            ref(numb-1, c+1);
            break;
        }
    }
}

signed main(){
    int n; cin >> n;
    a.resize(n);
    vis.resize(n, 0);
    for(int i = 0; i < n; i++){
        int& c = a[i]; cin >> c;
        r[c].push_back(i+1);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if (vis[i]) continue;
        ans++;
        ref(a[i], i+1);
    }
    cout << ans;
    return 0;
}