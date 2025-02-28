#include <bits/stdc++.h>

using namespace std;
#define int long long int
#define lll __int128_t
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rf(i, a, b) for (int i = (a); i >= (b); --i)
#define fe(x, y) for (auto& x : y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
using ii = pair<int, int>;
using ic = pair<int, char>;
template <typename T>
using v = vector<T>;
using vi = v<int>;
using vii = v<ii>;
using vvi = v<vi>;
using vc = v<char>;
using vvc = v<vc>;

const int MOD = 998244353;

int sum(int a, int b){
    return (a+b)%MOD;
}

void printdp(vvi& dp){
    cout << "P: "; fe(c, dp[0]) cout << c << " ";
    cout << "\nL: "; fe(c, dp[1]) cout << c << " "; 
    cout << "\n\n";
}

void put(vvi& dp, int i){
    int n = dp[0].size();
    if (n == 1) {dp[0][i] = -1; return;}
    if (i > 0) dp[0][i] = dp[1][i-1] = -1;
    if (i < n-1) dp[0][i] = dp[1][i+1] = -1;
}

void solve(){
    int n; cin >> n;
    vi a(n); fe(c, a) cin >> c;
    vvi dp(2, vi(n, 0));
    if (a[0] == a[1] && a[0] == 0) dp[1][0] = -1;
    fr(i, 1, n-2){
        if (a[i] == a[i+1] && a[i] == a[i-1]) dp[1][i] = -1;
        if (a[i] < a[i+1] && a[i] > a[i-1] || a[i] > a[i+1] && a[i] < a[i-1]) {
            put(dp, i-1);
            put(dp, i+1);
        }
    }
    // printdp(dp);
    {
        int l = 0, p = -2;
        fr(i, 0, n-1){
            if (a[i] != l) put(dp, i);
            if (dp[1][i] != -1 && i-1 != p){
                l++; p = i;
            }
        }
    }
    // printdp(dp);
    dp[0][0] = (dp[0][0] != -1 ? 1 : -1);
    dp[1][0] = (dp[1][0] != -1 ? 1 : -1);
    fr(i, 1, n-1){
        if (dp[0][i] != -1){
            if (a[i] > a[i-1]){
                if (dp[1][i-1] != -1) dp[0][i] = sum(dp[0][i], dp[1][i-1]);
            }else{
                if (dp[0][i-1] != -1) dp[0][i] = sum(dp[0][i], dp[0][i-1]);
                if (dp[1][i-1] != -1) dp[0][i] = sum(dp[0][i], dp[1][i-1]);
            }
        }
        if (dp[1][i] != -1){
            if (dp[0][i-1] != -1) dp[1][i] = sum(dp[1][i], dp[0][i-1]);
        }
    }
    // printdp(dp);
    int ans = 0;
    if (dp[0][n-1] != -1) ans = sum(ans, dp[0][n-1]);
    if (dp[1][n-1] != -1) ans = sum(ans, dp[1][n-1]);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    clock_t t1,t2;
    t1=clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t; cin >> t;
    while(t--){
        solve();
    }
    
    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms\n";
    #endif
    return 0;
}