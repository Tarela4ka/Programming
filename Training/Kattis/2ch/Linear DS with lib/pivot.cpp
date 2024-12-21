#include<bits/stdc++.h>

using namespace std;
// #define int long long int
// #define all(a) a.begin(), a.end()

signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n; cin >> n;
    vector<int> maxs(n), mins(n), a(n);
    for(auto& c : a)
        cin >> c;
    maxs[0] = 0;
    mins[n-1] = 1e9;
    for(int i = 1; i < n; i++)
        maxs[i] = max(maxs[i-1], a[i-1]);
    for(int i = n-2; i >= 0; i--)
        mins[i] = min(mins[i+1], a[i+1]);

    // for(int i = 0; i < n; i++)
    //     cout << maxs[i] << " ";
    // cout << endl;
    // for(int i = 0; i < n; i++)
    //     cout << mins[i] << " ";
    // cout << endl;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if (a[i] < mins[i] && a[i] >= maxs[i]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}