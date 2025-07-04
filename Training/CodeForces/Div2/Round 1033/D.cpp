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
const int maxa = 1e5+10;
const int maxm = 2e5+10;

int sum(int a, int b){
    return (a+b)%MOD;
}
int mult(int a, int b){
    return (a*b)%MOD;
}

int bin_pow(int n, int p){
    int r = 1;
    while(p){
        if (p&1) r = mult(r, n);
        p>>=1;
        n = mult(n, n);
    }
    return r;
}

vi fact(maxa, 1);

void solve(){
    int a, b, k; cin >> a >> b >> k;
    int n = (k*(a-1)+1)%MOD;
    int r = 1;
    rf(i, n, n-a+1) r = mult(r, i);
    cout << n << " " << sum(mult(mult(k, mult(bin_pow(fact[a], MOD-2), r)), b-1), 1) << "\n"; 
    
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

    fr(i, 2, maxa-1) fact[i] = mult(fact[i-1], i);

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