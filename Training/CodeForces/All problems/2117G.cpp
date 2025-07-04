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
using vvii = v<vii>;
using vvi = v<vi>;
using vc = v<char>;
using vvc = v<vc>;
 
const int MOD = 1e9+7;
const int INF = 4e18;
const int maxn = 2e7+10;

using ver = array<int, 3>;
vvii g;

void dijkstra(vi& d, int start){
    set<ii> q;
    q.insert({0, start});
    d[start] = 0;
    while(!q.empty()){
        auto [x, v] = *q.begin(); q.erase(q.begin());
        for(auto [c, w] : g[v]){
            if (d[c] > max(x, w)){
                q.erase({d[c], c});
                d[c] = max(x, w);
                q.insert({d[c], c});
            }
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;
    g.clear(); g.resize(n); v<ver> edg;
    fr(i, 0, m-1){
        int a, b, w; cin >> a >> b >> w; a--; b--;
        g[a].pb(mk(b, w));
        g[b].pb(mk(a, w));
        edg.push_back({a, b, w});
    }
    vi f1(n, INF), fn(n, INF);
    dijkstra(f1, 0); dijkstra(fn, n-1);
    int ans = INF;
    for(auto [a, b, w] : edg){
        ans = min(ans, min(w+max(w, max(f1[a], fn[b])), w+max(w, max(f1[b], fn[a]))));
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