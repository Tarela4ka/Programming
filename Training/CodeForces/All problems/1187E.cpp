#include<bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops") 
 
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
const int maxn = 2002;

int n, spTreeSum, root;
vi par, pathSum, dp, leafs, power, pref, deep;
vvi graph;

void dfs(int v, int p){
    par[v] = p; power[v] = graph[v].size(); deep[v] = deep[p] + 1; 
    if (power[v] == 1){
        leafs.pb(v);
    }
    fe(to, graph[v]){
        if (to != p){
            dfs(to, v);
            dp[v] += dp[to];
        }
    }
    dp[v] += 1;
}

void dfs2(int v, int p){
    pref[v] = pref[p] + (dp[v]-dp[p])*max(0LL, deep[v]-2); 
    fe(to, graph[v]){
        if (to != p){
            pathSum[to] = dp[to] + pathSum[v];
            dfs2(to, v);
        }
    }
}

void solve(){
    root = 0; cin >> n;
    graph.resize(n); 
    dp.assign(n, 0);
    pathSum.assign(n, 0); pref.assign(n, 0);
    deep.assign(n, 0); power.assign(n, 0); par.assign(n, root);
    fr(i, 0, n-2){
        int a, b; cin >> a >> b; a--; b--;
        graph[a].pb(b); graph[b].pb(a);
    }
    dfs(root, root);
    pathSum[root] = dp[root];
    dfs2(root, root);

    fe(c, dp) spTreeSum += c;
    int ans = 0;
    fe(c, leafs) ans = max(ans, spTreeSum - pathSum[c] + pref[c] + deep[c] * (n-1) + 1);
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