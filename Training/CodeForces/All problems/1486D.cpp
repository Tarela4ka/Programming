#include<bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops") 
 
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
const int maxn = 2002;
int n; vi a; 

int check(int x, int k){
    vi b(n, 0); fr(i, 0, n-1) b[i] = (a[i] >= x ? 1 : -1); 
    vi pref(n+1, 0); 
    fr(i, 1, n) pref[i] = pref[i-1]+b[i-1];
    map<int, int> cnt; int maxlen = 1;
    fr(i, 1, n){
        if (pref[i] > 0) maxlen = i;
        if (cnt[pref[i] - 1] != 0){
            maxlen = max(maxlen, i-cnt[pref[i]-1]);
        }
        if (cnt[pref[i]] == 0){
            cnt[pref[i]] = i;
        }
    }
    return (maxlen>=k);
}

void solve(){
    int k; cin >> n >> k;
    a.assign(n, 0); fe(c, a) cin >> c;
    int l = 1, r = n;
    while(r-l > 10){
        int mid = (l+r)/2;
        if (check(mid, k)){
            l = mid;
        }else{
            r = mid;
        }
    }
    rf(i, r, l){
        if (check(i, k)){
            cout << i << " ";
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

    // int t; cin >> t;
    // while(t--)
        solve();
 
    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms";
    #endif
    return 0;
}