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
const int INF = 1e18;
const int maxn = 6e6+10;


void solve(){ 
    int n, m; cin >> m >> n;
    vi a(n); fe(c, a) cin >> c;
    sort(all(a));
    vvi ans(m, vi(6, 0));
    int k = 0;
    fr(j, 0, m-1){
        if (j % 2 == 0){
            fr(i, 0, 5){
                if (i%2 == 0) ans[j][i] = a[k];
                else ans[j][i] = a[n-1-k];
            }
        }else{
            fr(i, 0, 5){
                if (i%2 == 1) ans[j][i] = a[k];
                else ans[j][i] = a[n-1-k];
            }
            k++;
        }
    }
    fe(c, ans){
        fe(v, c){
            cout << v << " ";
        }
        cout << '\n';
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

    int t; cin >> t;
    while(t--) solve();
 
    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms";
    #endif
    return 0;
}