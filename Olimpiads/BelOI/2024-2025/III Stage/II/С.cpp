#include<bits/stdc++.h>

using namespace std;
#define int long long int
#define lll __int128_t
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rf(i, a, b) for (int i = (a); i >= (b); --i)
#define fe(x, y) for (auto& x : y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
#define pb(b) push_back(b)
#define LSOne(S) (S & (-S))
using ii = pair<int, int>;
using ic = pair<int, char>;
template <typename T>
using v = vector<T>;
using vi = v<int>;
using vii = v<ii>;
using vvi = v<vi>;
using vc = v<char>;
using vvc = v<vc>;

const int MOD = 998244353;
const int INF = 1e16;

int logn;
vvi g, up;
vvi dp;
vi p, d;
vi first, last;
v<vii> lcas;

void dfs(int v, int par, int deep, int& t){
    first[v] = t++;
    fe(c, g[v]){
        if (c != par){
            d[c] = deep+1;
            p[c] = v;
            dfs(c, v, deep+1, t);
        }
    }
    last[v] = t++;
}

int lca(int v, int u){
    if (d[v] < d[u]) swap(v, u);
    rf(i, logn, 0){
        if (d[up[v][i]] >= d[u])
            v = up[v][i];
    }
    if (v == u) return v;
    rf(i, logn, 0){
        if (up[v][i] != up[u][i]){
            v = up[v][i];
            u = up[u][i];
        }
    }
    return p[v];
}

struct fenwick{
private:
    vvi ft;
    int n;
public:
    void init(int m){
        n = m;
        ft.assign(n+1, vi(2, 0));
    }
    void upd(int type, int v, int zn){
        update(type, first[v]+1, zn);
        update(type, last[v]+1, -zn);
    }
    int rsq(int type, int i){
        i = first[i]+1;
        int res = 0;
        for(; i; i-=LSOne(i)) res += ft[i][type];
        return res;
    }
    void update(int type, int i, int d){
        for(; i <= n; i+=LSOne(i))
            ft[i][type] += d;
    }
};

fenwick ft;

void dpupd(int par, int v){
    fe(c, g[v]){
        if (c != par){
            dpupd(v, c);
            dp[v][0] += max(dp[c][1], dp[c][0]);
        }
    }
    
    ft.upd(0, v, dp[v][0]);
    dp[v][1] = dp[v][0];
    for(auto [a, b] : lcas[v]){
        int res = 0;
        if (a != v){
            res -= dp[v][0];
            res += ft.rsq(0, a)-ft.rsq(1, a);
        }
        res += ft.rsq(0, b)-ft.rsq(1, b);
        dp[v][1] = max(dp[v][1], res+1);
    }
    ft.upd(1, v, dp[v][1]);
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
    while(t--){
        int n, m; cin >> n >> m;
        logn = log2(n)+1;
        p.assign(n, 0); d.assign(n, 0);
        first.assign(n, 0); last.assign(n, 0);
        g.clear(); g.resize(n);
        up.clear(); up.resize(n, vi(logn+1));
        dp.clear(); dp.resize(n, vi(2, 0));
        ft.init(n*2); lcas.clear(); lcas.resize(n);
        fr(i, 0, n-2){
            int a, b; cin >> a >> b; a--; b--;
            g[a].pb(b); g[b].pb(a);
        }
        d[0] = 0; p[0] = 0; 
        {int c = 0; dfs(0, 0, 0, c);}
        fr(i, 0, n-1) up[i][0] = p[i];
        fr(j, 1, logn)
            fr(i, 0, n-1) 
                up[i][j] = up[up[i][j-1]][j-1];
        fr(i, 0, m-1){
            int a, b; cin >> a >> b; a--; b--;
            lcas[lca(a, b)].push_back(mk(a, b));
        }
        dpupd(0, 0);
        cout << max(dp[0][1], dp[0][0]) << "\n";
    }

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