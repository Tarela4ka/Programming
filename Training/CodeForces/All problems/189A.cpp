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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n; cin >> n;
    vi p(3); 
    for(auto& c : p) cin >> c;
    vi dp(n+1, 0);
    sort(all(p));

    for(int i = 1; i <= n; i++){
        int k = 0;
        for(auto c : p){
            if (c > i) break;
            if (dp[i-c] > dp[i] || (i-c == 0 && dp[i-c] == dp[i])){
                dp[i] = dp[i-c];
                k = c;
            }
        }
        for(auto c : p) 
            if (k == c) {dp[i]++; break;}
    }
    // for(auto c : dp) cout << c << " ";
    cout << dp[n];
    return 0;
}