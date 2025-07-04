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
#define lc(S) ((S << 1))
#define rc(S) ((S << 1) + 1)
// #define par(S) ((S << 1) + 2)
using ii = pair<int, int>;
using ic = pair<int, char>;
template <typename T>
using v = vector<T>;
using vi = v<int>;
using vii = v<ii>;
using vvii = v<vii>;
using vvi = v<vi>;
using vc = v<char>;
using vvc = v<vc>;
 
const int MOD = 1e9+7;
const int INF = 1e9;
const int maxn = 1e7+10;
const int maxm = 2e5+10;

void solve(){
    int n, m; cin >> n >> m;
    if (m > (n*n+n)/2 || m < n){
        cout << -1 << '\n';
        return;
    }
    vi pref(n, 0);
    fr(i, 0, n-1){
        if (m == 0) break;
        int l = 0, r = n-i-1;
        while(r-l > 5){
            int mid = (l+r)/2;
            if (m - mid > 0) l = mid;
            else r = mid;
        }
        int k = 0;
        fr(j, l, r) if (m-j-1 >= 0) k = j;
        pref[k] = i+1;
        m -= k+1;
    }
    {
        int p = 0;
        fr(i, 0, n-1){
            if (pref[i] != 0){
                fr(j, p, i) pref[j] = pref[i];
                p = i+1;
            }
        }
    }
    int p = 0; set<int> s; fr(i, 1, n) s.insert(-i);
    fr(i, 0, n-1){
        if (pref[i] != p){
            p = pref[i]; s.erase(p);
        }else{
            pref[i] = -(*s.begin()); s.erase(s.begin());
        }
    }
    // fe(c, pref) cout << c << " ";
    cout << pref[0] << '\n';
    fr(i, 0, n-2){
        cout << pref[i] << " " << pref[i+1] << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    srand(time(NULL));
    #ifdef DEBUG
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