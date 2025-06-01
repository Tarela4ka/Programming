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
const int INF = 1e18;
const int maxn = 6e6+10;


void solve(){
    int n; cin >> n;
    if (n%2 == 0){
        cout << "NO\n";
        return;
    }
    int a = (3*n+3)/2;   
    set<int> s;
    fr(i, 1, 2*n) s.insert(i);
    vii ans; int p = 0;
    fr(i, a, a+n-1){
        bool f = 0;
        for(auto it = s.lower_bound(p); it != s.end(); it++){
            int c = *it, x = i-c; p = c;
            if (c > n) break;
            // cout << c << " " << x << endl;
            if (x == i) continue; 
            if (s.find(x) != s.end()){
                ans.push_back({c, x});
                // cout << c << " " << x << endl;
                s.erase(c); s.erase(x);
                f = 1;
                break;
            }
        }
        if (!f){
            p = 0; i--;
        }
    }
    cout << "YES\n";
    fe(c, ans){
        cout << c.first << " " << c.second << "\n";
    }
    
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
    while(t--) solve();
 
    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms\n";
    #endif
    return 0;
}