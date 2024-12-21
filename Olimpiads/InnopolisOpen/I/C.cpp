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

const int MOD = 998244353;

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    clock_t t1,t2;
    t1=clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n; cin >> n;
    vi p{}; p.push_back(0);
    for(int i = 0; i <= 12; i++){
        int x = 2*pow(3, i);
        queue<int> q;
        for(auto c : p) q.push(x+c);
        while(!q.empty()) {
            p.push_back(q.front()); q.pop();
        }
    }
    // cout << *p.rbegin() << endl;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    // for (int i = 0; i < n; ++i){
    //     for (auto c : p){
    //         if (i + c + 1 > n) break;
    //         dp[i + c + 1] = (dp[i] + dp[i + c + 1]) % MOD;
    //     }
    // }
    for(int i = 1; i <= n; i++){
        for(auto c : p){
            if (i-c-1 < 0) break;
            dp[i] += dp[i-c-1];
        }
        dp[i] %= MOD;
    }
    // for(int i = 1; i <= n; i++){
    //     for(auto c : p){
    //         if (i-c-1 < 0) break;
    //         dp[i] = (dp[i-c-1]+dp[i]);
    //     }
    //     dp[i]%=MOD;
    // }

    cout << dp[n];

    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms";
    #endif
    return 0;
}