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
    int n, q, k; cin >> n >> q >> k;
    vi a(n); fe(c, a) cin >> c;
    vi pref(n, 0);
    pref[1] = (a[1]-2);
    fr(i, 1, n-2){
        pref[i] = pref[i-1] + (a[i+1]-a[i-1])-2;
    }
    // pref[n-1] = pref[n-2] + (k-a[n-2]-1);
    // fe(c, pref) cout << c << ' '; cout << '\n';
    while(q--){
        int l, r; cin >> l >> r; l--; r--;
        if (r-l == 0){
            cout << k-1 << '\n';
            continue;
        }
        int ans = pref[r-1]-pref[l] + (a[l+1]-1-1) + (k-a[r-1]-1);
        cout << ans << '\n';
    }
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
    
    // int t; cin >> t;
    // while(t--) 
        solve();
 
    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms";
    #endif
    return 0;
}