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
const int INF = 4e18;
const int maxn = 6e6+10;

void solve(){
    int n, m; cin >> n >> m;
    vi a(n); a[0] = 1; fr(i, 1, n-1) cin >> a[i];
    vi b(n); fe(c, b) cin >> c;
    sort(all(a)); sort(all(b));
    int l = 0, r = n;
    while(r-l > 10){
        int mid = (l+r)/2;
        bool f = 1;
        fr(i, 0, n-mid-1){
            if (a[i] >= b[mid+i]){
                f = 0;
                break;
            } 
        }
        if (f){
            r = mid;
        }else{
            l = mid;
        }
    }
    // cout << l << " " << r << '\n';
    // fe(c, a) cout << c << " "; cout << '\n';
    // fe(c, b) cout << c << " "; cout << '\n';
    fr(mid, l, r){
        bool f = 1;
        // cout << mid << " ";
        fr(i, 0, n-mid-1){
            if (a[i] >= b[mid+i]){
                f = 0;
                // cout << i << " " << mid+i << " " << a[i] << " " << b[mid+i] << '\n';
                break;
            } 
        }
        if (f){
            cout << mid << '\n';
            return;
        }
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
    while(t--) 
        solve();
 
    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms";
    #endif
    return 0;
}