#include <bits/stdc++.h>

using namespace std;
#define int long long int
#define lll __int128_t
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rf(i, a, b) for (int i = (a); i >= (b); --i)
#define fe(x, y) for (auto& x : y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
using ii = pair<int, int>;
using ic = pair<int, char>;
#define LSOne(S) (S & (-S))
template <typename T>
using v = vector<T>;
using vi = v<int>;
using vii = v<ii>;
using vvi = v<vi>;
using vc = v<char>;
using vvc = v<vc>;

const int MOD = 998244353;

void solve(){
    int n,m,q; cin >> n >> m >> q;
    vvi a(n, vi(m)); fe(c, a) fe(v, c) cin >> v;
    vvi b(m, vi(n));
    fr(i,0,m-1) b[i][0] = a[0][i];
    fr(i, 1, n-1){
        fr(j, 0, m-1){
            b[j][i] = (b[j][i-1]|a[i][j]);
        }
    }
    // fe(c, b){
    //     fe(v, c) cout << v << " ";
    //     cout << "\n";
    // }
    while(q--){
        int m; cin >> m;
        int l = 0, r = n-1;
        while(m--){
            int i, v; char o;
            cin >> i >> o >> v; i--;
            if (o == '>'){
                int ind = upper_bound(all(b[i]), v)-b[i].begin();
                l = max(ind, l);
            }else{
                int ind = (lower_bound(all(b[i]), v) - b[i].begin()) - 1;
                r = min(r, ind);
            }
        }
        if (r < l){
            cout << -1 << '\n';
        }else{
            cout << l+1 << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    clock_t t1,t2;
    t1=clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    // int t; cin >> t;
    // while(t--){
        solve();
    // }
    
    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms\n";
    #endif
    return 0;
}