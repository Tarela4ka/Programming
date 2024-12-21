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

const int INF = 1e9;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; cin >> n;
    vi a(n);
    for(auto& c : a) cin >> c;
    vi dp(n+1, INF);
    for(int i = 0; i < n; i++){
        int j = 0;
        for(; dp[j] < a[i]; j++);
        dp[j] = a[i];
    }
    int m = 0;
    // for(auto c : dp) cout << c << endl;
    for(; dp[m] != INF; m++);
    cout << m;
    return 0;
}