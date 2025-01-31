#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define fr(i, a, b) for(int i = (a); i <= (b); i++)
#define rf(i, a, b) for(int i = (a); i >= (b); i--)
#define fe(c, a) for(auto& c : a)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template <typename T>
using v = vector<T>;
using vi = v<int>;
using vvi = v<vi>;
using ii = pair<int, int>;
using vii = v<ii>;

const int INF = 1e9;
vvi g;
vii a;
vi cost;

void dfs1(vi& vis, int v){
    vis[v] = 1;
    fe(to, g[v]){
        if (!vis[to])
            dfs1(vis, to);
    }
    int Max = a[v].first;
    fe(to, g[v]){
        if (!vis[to]){
            Max = max(Max, cost[to]);
        }
    }
    cost[v] = min(a[v].second, Max);
    vis[v] = 0;
}

void dfs2(vi& vis, int v, int& res){
    vis[v] = 1;
    fe(to, g[v]){
        if (!vis[to]){
            res += max(cost[to]-cost[v], 0LL);
            dfs2(vis, to, res);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        g.clear(); g.resize(n);
        a.clear(); a.resize(n);
        cost.clear(); cost.resize(n, -INF);
        fe(c, a) 
            cin >> c.first >> c.second;
        fr(i, 0, n-2){
            int a,b; cin >> a >> b; a--; b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vi vis(n, 0);
        dfs1(vis, 0);
        vis.assign(n, 0);
        int res = 0; dfs2(vis, 0, res);
        cout << cost[0]+res;
        cout << "\n";
    }
    return 0;
}