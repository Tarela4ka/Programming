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
    vi a(n); fe(c, a) cin >> c;
    map<int, int> cnt; 
    fe(c, a) cnt[c]++;
    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        int D = x*x-4*y; 
        if (D < 0){
            cout << 0 << ' ';
        }else if (D == 0){
            if (x%2 == 0){
                int a = cnt[x/2];
                cout << (a*a-a)/2 << ' ';
            }else{
                cout << 0 << ' ';
            }
        }else{
            int a1 = (x+sqrt(D))/2, a2 = (x - sqrt(D))/2;
            if (a1 + a2 == x && a1 * a2 == y){
                cout << cnt[a1] * cnt[a2] << ' ';
            }else{
                cout << 0 << ' ';
            }
        }
    }
    cout << '\n';
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
    cout << '\n' << diff << "ms";
    #endif
    return 0;
}