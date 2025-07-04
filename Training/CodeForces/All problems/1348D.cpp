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

void solve(){
    int n; cin >> n;
    int k = 1;
    while(n > (1<<k)-1) k++; k--;
    vi b(k); 
    if (k >= 3){
        b[0] = 1; fr(i, 1, k-3) b[i] = b[i-1]*2;
        int bact = 1, m = 1; 
        fr(i, 0, k-3){
            bact += b[i];
            m += bact;
        }
        n = n-m-2*bact;
        // cout << n << '\n';
        b[k-2] = min(n/2, bact); b[k-1] = n-2*b[k-2];
    }else if (k == 2){
        int bact = 1, m = 1; 
        n = n-m-2*bact; 
        b[k-2] = min(n/2, bact); b[k-1] = n-2*b[k-2];
    }else{
        if (n == 3) b[0] = 1;
    }
    cout << k << '\n';
    fe(c, b) cout << c << ' '; cout << '\n';
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