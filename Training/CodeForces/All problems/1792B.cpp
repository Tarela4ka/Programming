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
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    int ans = a1, n1 = a1, n2 = a1;
    if (a1 == 0){
        cout << 1 << "\n";
        return;
    }
    int x = min(a2, a3);
    ans += 2*x; a2-=x; a3-=x;
    a2 = max(a2, a3);
    x = min(a1+1, a2);
    ans += x;
    a2 -= x;
    ans += min(a1-x+1, a4);
    cout << ans << endl;
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