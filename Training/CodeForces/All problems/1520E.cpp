#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops") 
 
using namespace std;
#define int long long int
#define lll __int128_t
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rf(i, a, b) for (int i = (a); i >= (b); --i)
#define fe(tx, ty) for (auto& tx : ty)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
#define pb(b) push_back(b)
#define LSOne(S) (S & (-S))
#define lc(S) ((S << 1) + 1)
#define rc(S) ((S << 1) + 2)
using ii = pair<int, int>;
using ic = pair<int, char>;
template <typename T>
using v = vector<T>;
using vi = v<int>;
using vii = v<ii>;
using vvi = v<vi>;
using vc = v<char>;
using vvc = v<vc>;
 
const int MOD = 1e9+7;
const int INF = 4e18;
const int maxn = 1e6+10;

void solve(){
    int n; cin >> n; 
    string s; cin >> s;
    int o = 0; fe(c, s) if (c=='*')o++;
    vi pref(n+1, 0), suf(n+1, 0);
    if (s[0] == '*') pref[1] = n-1;
    fr(i, 2, n){
        pref[i] = pref[i-1];
        if (s[i-1] == '*') pref[i] += n-i;
    }
    if (s[n-1] == '*') suf[n-1] = n-1;
    rf(i, n-2, 0){
        suf[i] = suf[i+1];
        if (s[i] == '*') suf[i] += i;
    }
    int l = 0, r = o, ans = INF;
    // fe(c, pref) cout << c << " "; cout << '\n';
    // fe(c, suf ) cout << c << " "; cout << '\n';
    fr(i, 0, n-1){
        if (s[i] == '*') r--;
        int res = (pref[i]-l*(n-i-1)) + (suf[i+1] - r*i);
        // cout << pref[i] << " " << l*(n-i-1) << " " << suf[i+1] << " " << r*i << " " << (pref[i]-l*(n-i-1)) + (suf[i+1] - r*i) << '\n';
        // cout << l << " " << r << '\n';
        if (s[i] == '*'){
            res -= (l*l+l)/2 + (r*r+r)/2;
        }else{
            if (l > r){
                res -= (l*l+l)/2 + (r*r-r)/2;
            }else{
                // cout << "YES\n" << res << " " << (l*l-l)/2 << " " << (r*r+r)/2 << '\n';
                res -= (l*l-l)/2 + (r*r+r)/2;
            }
        }
        // cout << res << '\n';
        ans = min(ans, res);
        if (s[i]=='*'){
            l++;
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    srand(time(NULL));
    clock_t t1,t2;
    t1=clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t; cin >> t;
    while(t--) 
        solve();
 
    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms";
    #endif
    return 0;
}