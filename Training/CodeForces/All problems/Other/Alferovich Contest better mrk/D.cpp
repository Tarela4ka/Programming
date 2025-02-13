#include<bits/stdc++.h>

using namespace std;
#define int long long
#define lll __int128_t
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rf(i, a, b) for (int i = (a); i >= (b); --i)
#define fe(x, y) for (auto& x : y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
using ii = pair<int, int>;
using ic = pair<int, char>;
template <typename T>
using v = vector<T>;
using vi = v<int>;
using vii = v<ii>;
using vvi = v<vi>;

const int MOD = 998244353;
const int INF = 1e14+10;
const int maxn = 1e5+10;
const int logn = 18;

int dp[maxn][logn];
int p[maxn];
int d[maxn];

vvi g;

void dfs(vi& vis, int v, int dep){
    vis[v] = 1;
    fe(c, g[v]){
        if (!vis[c]){
            p[c] = v;
            d[c] = dep+1;
            dfs(vis, c, dep+1);
        }
    }
}

int lca(int v, int u){
    if (d[v] > d[u]) swap(v, u);
    rf(i, logn-1, 0)
        if (d[dp[u][i]] - d[v] >= 0)  
            u = dp[u][i];

    if (v == u) return v;
    rf(i, logn-1, 0){
        if (dp[v][i] != dp[u][i]){
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return p[v];
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    clock_t t1,t2;
    t1=clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, k, dist; cin >> n >> dist >> k;
    // if (k == 0){
    //     if (dist == 0) cout << n;
    //     else cout << 0;
    //     return 0;
    // }
    g.resize(n+1);
    fr(i, 0, n-2){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi vis(n+1, 0);
    p[1] = 1; d[1] = 0;
    dfs(vis, 1, 0);
    // fr(i, 1, n) cout << p[i] << " ";
    // cout << '\n';
    // fr(i, 1, n) cout << d[i] << " ";
    // cout << "\n\n";
    // fr(i, 1, n){
    //     fr(j, 1, n)
    //         cout << i << " " << j << ": " << lca(i, j) << "\n";
    //     cout << endl;
    // }
    fr(i, 1, n)
        dp[i][0] = p[i];
    fr(j, 1, logn-1)
        fr(i, 1, n)
            dp[i][j] = dp[dp[i][j - 1]][j - 1];

    int ans = 0;
    fr(i, 1, n){
        int v = i, u = k^v;
        if (u > n || u > v || u < 1) continue;
        int l = lca(v, u);
        if (d[v]+d[u]-2*d[l] == dist) ans++;
    }
    cout << ans;

    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms\n";
    #endif
    return 0;
}
// ⠀⢸⠂⠀⠀⠀⠘⣧⠀⠀⣟⠛⠲⢤⡀⠀⠀⣰⠏⠀⠀⠀⠀⠀⢹⡀
// ⠀⡿⠀⠀⠀⠀⠀⠈⢷⡀⢻⡀⠀⠀⠙⢦⣰⠏⠀⠀⠀⠀⠀⠀⢸⠀
// ⠀⡇⠀⠀⠀⠀⠀⠀⢀⣻⠞⠛⠀⠀⠀⠀⠻⠀⠀⠀⠀⠀⠀⠀⢸⠀
// ⠀⡇⠀⠀⠀⠀⠀⠀⠛⠓⠒⠓⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀
// ⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠀
// ⠀⢿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⠀⠀⢀⡟⠀
// ⠀⠘⣇⠀⠘⣿⠋⢹⠛⣿⡇⠀⠀⠀⠀⣿⣿⡇⠀⢳⠉⠀⣠⡾⠁⠀
// ⣦⣤⣽⣆⢀⡇⠀⢸⡇⣾⡇⠀⠀⠀⠀⣿⣿⡷⠀⢸⡇⠐⠛⠛⣿⠀
// ⠹⣦⠀⠀⠸⡇⠀⠸⣿⡿⠁⢀⡀⠀⠀⠿⠿⠃⠀⢸⠇⠀⢀⡾⠁⠀
// ⠀⠈⡿⢠⢶⣡⡄⠀⠀⠀⠀⠉⠁⠀⠀⠀⠀⠀⣴⣧⠆⠀⢻⡄⠀⠀
// ⠀⢸⠃⠀⠘⠉⠀⠀⠀⠠⣄⡴⠲⠶⠴⠃⠀⠀⠀⠉⡀⠀⠀⢻⡄⠀
// ⠀⠘⠒⠒⠻⢦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⠞⠛⠒⠛⠋⠁⠀
// ⠀⠀⠀⠀⠀⠀⠸⣟⠓⠒⠂⠀⠀⠀⠀⠀⠈⢷⡀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠙⣦⠀⠀⠀⠀⠀⠀⠀⠀⠈⢷⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⣼⣃⡀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣆⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠉⣹⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡆ Made by @Tarela4ka