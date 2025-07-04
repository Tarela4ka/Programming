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
const int maxn = 1e5+10;
const int maxm = 2e5+10;

void solve(){
    int n, m, q; cin >> n >> m >> q;
    vi a(n+1, 0); fr(i, 1, n) cin >> a[i];
    map<signed, int> T;
    vi del; 
    {
        int s = sqrt(m);
        fr(i, 1, s){
            if (m%i == 0){
                del.pb(i);
                if (i*i != m && i != 1) del.pb(m/i);
            }
        }
    }
    fe(p, del){
        fr(i, 1, n){
            if (a[i-1]%p > a[i]%p) T[p]++;
        }
    }
    while(q--){
        int z; cin >> z;
        if (z == 1){
            int i, x; cin >> i >> x;
            fe(p, del){
                if (a[i-1]%p > a[i]%p) T[p]--;
                if (a[i-1]%p > x%p) T[p]++;
                if (i != n){
                    if(a[i+1]%p < a[i]%p) T[p]--;
                    if(a[i+1]%p < x%p) T[p]++;
                } 
            }
            a[i] = x;
        }else{
            int k; cin >> k; 
            int p = gcd(k, m);
            // cout << p << ": " << T[p] << " " << a[n] << '\n'; 
            if (T[p]*p + a[n]%p < m){
                cout << "YES\n";
            } else{
                cout << "NO\n";
            }
        }
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