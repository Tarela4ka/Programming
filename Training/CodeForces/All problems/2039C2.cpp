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
    int x, m; cin >> x >> m;
    int ans = 0;
    fr(i, 1, min(m, x-1)){
        if (((i^x)%x == 0) || ((i^x)%i == 0)) ans++;
    }
    int l = 0, r = (2*m)/x;
    while(r-l > 1e3){
        int mid = (l+r)/2;
        if(((mid*x)^x) > m) r = mid;
        else l = mid;
    } 
    if (m >= x){
        ans += l;
        for(int i = (l+1); i <= r+1000; i++){
            if (((i*x) ^ x) <= m) ans++;
        }
    }
    cout << ans << '\n';
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
    
    int t; cin >> t;
    while(t--){
        solve();
    }
    
    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms\n";
    #endif
    return 0;
}