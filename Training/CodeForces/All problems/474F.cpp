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
const int INF = 4e18;
const int maxn = 1e5+10;

int find(vi& a, int l, int r){
    return max(0LL, upper_bound(all(a), r) - lower_bound(all(a), l)); 
}

vi tree;
int N = 1;

void build(vi& a){
    while(N < a.size()) N<<=1;
    tree.resize(N*2, 0);
    fr(i, N, 2*N-1) if (i-N < a.size()) tree[i] = a[i-N];
    rf(i, N-1, 1) tree[i] = gcd(tree[lc(i)], tree[rc(i)]);
}

int query(int l, int r){
    l+=N; r+=N+1; int res = 0;
    for(; l < r; l>>=1, r>>=1){
        if (l&1) res = gcd(res, tree[l++]); 
        if (r&1) res = gcd(res, tree[--r]); 
    }
    return res;
}

void solve(){
    int n; cin >> n;
    vi a(n); fe(c, a) cin >> c;
    unordered_map<int, vi> m;
    fr(i, 0, n-1) m[a[i]].pb(i);
    build(a);
    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r; l--; r--;
        cout << r-l+1-find(m[query(l, r)], l, r) << '\n';
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