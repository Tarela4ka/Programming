#include<bits/stdc++.h>

using namespace std;
#define int long long int
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
using ii = pair<int, int>;
using vii = vector<ii>;

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; cin >> n;
    vi a(n);
    for(auto& c : a) cin >> c;

    sort(all(a));

    vi vis(n-1, 0);
    vi d(n-1);

    for(int i = 1; i < n; i++) d[i-1] = a[i]-a[i-1];
    vi dp(n, 0);
    dp[0] = d[0];
    dp[1] = d[0] + d[1];
    for(int i = 2; i < n-1; i++){
        dp[i] = d[i]+min(dp[i-1], dp[i-2]);
    }
    cout << dp[n-2];
    return 0;
}