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
    int n,k; cin >> n >> k;
    vi dp(n+1);
    dp[0] = 1;
    dp[1] = k-1;
    for(int i = 2; i <= n; i++){
        dp[i] = (k-1)*(dp[i-1]+dp[i-2]);
    }
    cout << dp[n];
    return 0;
}