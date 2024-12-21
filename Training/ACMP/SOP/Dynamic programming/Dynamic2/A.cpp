#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define int long long int
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;
using vs = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    int n; cin >> n;
    vi a(n);
    for(auto& c : a) cin >> c;
    vi dp(n+1);
    dp[0] = 0;
    dp[1] = abs(a[1]-a[0]);
    for(int i = 2; i < n; i++){
        dp[i] = min(dp[i-2]+3*abs(a[i-2]-a[i]), dp[i-1]+abs(a[i-1]-a[i]));
    }
    cout << dp[n-1];
    return 0;
}