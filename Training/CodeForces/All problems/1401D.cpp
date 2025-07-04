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
const int maxn = 6e6+10;

int mx;
vvi g;
vi d;
vi pr;

void dfs(int v, int par){
    pr[v] = par;
    fe(c, g[v]){
        if (c != par){
            dfs(c, v);
            d[v] += d[c];
        }
    }
}

void solve(){
    int n; cin >> n;
    g.clear(); g.resize(n);
    d.assign(n, 1);
    pr.clear(); pr.resize(n);
    vii e;
    fr(i, 0, n-2){
        int a, b; cin >> a >> b; a--; b--;
        e.pb(mk(a,b));
        g[a].pb(b);
        g[b].pb(a);
    }
    int m; cin >> m;
    vi p(m); fr(i, 0, m-1) cin >> p[i];
    sort(rall(p));
    vi por;
    if (n-1 >= m){
        por.resize(n-1, 1);
        fr(i, 0, m-1) por[i] = p[i];
    }else{
        por.pb(p[0]);
        fr(i, 1, m-n+1) por[0] = (por[0]*p[i])%MOD;
        fr(i, m-n+2, m-1) por.pb(p[i]);
    }
    // fe(c, )
    // fe(c, por) cout << c << ' ';
    vi edg;
    dfs(0, 0);
    for(auto[a,b] : e){
        if (a == pr[b]) swap(a,b);
        edg.pb(d[a]*(d[0]-d[a]));
    }
    sort(rall(edg));
    int ans = 0;
    fr(i, 0, n-2){
        ans = (ans+(edg[i]*por[i]))%MOD;
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