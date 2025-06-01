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
#define pb(a) push_back(a)
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
const int INF = 1e16;
const int ss = 20;
const int maxn = 1e5+20;

void solve(){
    int n; cin >> n;
    map<int, int> cnt;
    fr(i, 0, n-1){
        int x; cin >> x;
        cnt[x]++;
    }
    ii p = *cnt.begin();
    bool f = 0;
    fe(x, cnt){
        int c = x.second;
        if (x.first-p.first > 1) f = false;
        p = x;
        if (c >= 4){
            cout << "YES\n";
            return;
        }
        if (f && c >= 2){
            cout << "YES\n";
            return;
        }else if(!f){
            if (c >= 2){
                f = true;
            }
        }
    }
    cout << "No\n";
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    clock_t t1,t2;
    t1=clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w",  stdout);
    #endif
    
    int t; cin >> t;
    while(t--)
        solve();
    
    
    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms\n";
    #endif
    return 0;
}