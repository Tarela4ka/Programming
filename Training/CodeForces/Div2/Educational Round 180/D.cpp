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
vvi g; vvii gor; 

void dfs(int v, int par, int col){
    fe(c, g[v]){
        if (c != par){
            dfs(c, v, !col);
        }
        gor[v].push_back({c, col});
    }
}

void dfs2(int par, int v){
    fe(c, gor[v]){
        if (c.first != par){
            dfs2(v, c.first);
        }
        c.second = !c.second;
    }
}

void solve(){
    int n; cin >> n;
    g.clear(); g.resize(n);
    gor.clear(); gor.resize(n);
    fr(i, 0, n-2){
        int a, b; cin >> a >> b; a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    dfs(0, 0, 0);
    bool f = 0;
    fr(i, 0, n-1){
        if (g[i].size() == 2){
            dfs2(i, gor[i].begin()->first);
            gor[i][0].second = !gor[i][0].second;
            f = 1;
            break;
        }
    }
    if (!f){
        cout << "NO\n";
        return;
    } cout << "YES\n";
    set<pair<int, int>> ans;
    fr(i, 0, n-1){
        fe(v, gor[i]){
            if (v.second == 0){
                ans.insert({i+1, v.first+1});
            }else{
                ans.insert({v.first+1, i+1});
            }
        }
    }
    fe(c, ans){
        cout << c.first << " " << c.second << '\n';
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