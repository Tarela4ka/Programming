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
using vvii = v<vii>;
using vvi = v<vi>;
using vc = v<char>;
using vvc = v<vc>;
 
const int MOD = 1e9+7;
const int INF = 4e18;
const int maxa = 1e7+10;

int x, y, a, b;

void solve(){
    cin >> x >> y >> a >> b;
    if (x > y) swap(x, y);
    if (a > b) swap(a, b);
    if (a == b){
        cout << min(x/a, y/b) << '\n';
        return;
    }
    int l = 0, r = 2e9;
    while(r-l > 10){
        int m = (r+l)/2;
        int left = ceill(double(x-b*m)/(a-b));
        int right = floorl(double(y-a*m)/(b-a));
        if (max(left, 0LL) <= min(m, right)){
            l = m;
        }else{
            r = m;
        }
    }
    int ans = 0;
    fr(m, l, r){
        int left = ceill(double(x-b*m)/(a-b));
        int right = floorl(double(y-a*m)/(b-a));
        if (max(left, 0LL) <= min(m, right)) ans = m;
    }
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