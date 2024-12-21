#include<bits/stdc++.h>

using namespace std;
#define int long long int
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n,m; cin >> n >> m;
    vvi a(n,vi(m));
    for(auto& c : a) for(auto& v : c) cin >> v;
    vvi dp(n, vi(m));
    dp[0][0] = a[0][0];
    for(int i = 1; i < n; i++)
        dp[i][0] = dp[i-1][0] + a[i][0];
    
    for(int i = 0; i < n; i++){
        for(int j = 1; j < m; j++){
            if (i == 0){
                dp[i][j] = dp[i][j-1] + a[i][j];
                continue;
            }
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + a[i][j];
        }
    }
    for(int i = 0; i < n; i++) printf("%d ", dp[i][m-1]);
    return 0;
}