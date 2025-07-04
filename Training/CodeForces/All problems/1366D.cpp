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

vi lastprime(maxa, 0);

void solve(){
    int n; cin >> n; 
    vi a(n); fe(c, a) cin >> c;
    vii ans(n);
    fr(i, 0, n-1){
        int c = a[i];
        int p = lastprime[c];
        while(c % (p * lastprime[c]) == 0) p*=lastprime[c];
        if (c/p == 1){
            ans[i].first = ans[i].second = -1;
        }else {
            ans[i].first = p;
            ans[i].second = c/p;
        }
    }
    fe(c, ans) cout << c.first << " "; cout << '\n';
    fe(c, ans) cout << c.second << " "; cout << '\n';
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

    fr(i, 2, maxa){
        if (!lastprime[i]){
            for(int j = i; j < maxa; j+=i){
                lastprime[j] = i;
            }
        }
    }
    
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