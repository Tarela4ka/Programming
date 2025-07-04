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

vvi let(maxm, vi(10, 0));

int sum(int a, int b){
    return (a+b)%MOD;
}

void solve(){
    int n, m; cin >> n >> m;
    int ans = 0;
    while(n){
        int d = n%10; n/=10;
        int s = 0;
        fe(c,  let[max(0LL, m-(9-d))]) s = sum(s, c);
        ans = sum(ans, s);
    }
    cout << ans << '\n';
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

    vi dig(10, 0);
    dig[9] = 1;
    let[0] = dig;
    fr(i, 1, maxm-1){
        int t0 = dig[9];
        dig[9] = 0;
        rf(j, 8, 0){
            dig[j+1] = dig[j];
            dig[j] = 0;
        }
        dig[0] = sum(dig[0], t0);
        dig[1] = sum(dig[1], t0);
        let[i] = dig;
    }

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