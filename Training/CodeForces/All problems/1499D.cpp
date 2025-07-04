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
const int maxn = 2e7+10;

int a, b, res, ans; 
signed d[maxn] = {};
v<bool> prime(maxn, 0);

int power(int a, int p){
    int res = 1;
    while(p){
        if (p&1) res *= a;
        a = a*a;
        p>>=1;
    }
    return res;
}

void resh(int GCD){
    if ((res/GCD + b) % a != 0) return; 
    int LCM = GCD*(res/GCD+b)/a;
    int ke = LCM/GCD;
    if (ke <= maxn-10) {
        ans += power(2, d[ke]);
        return;
    }
}

void solve(){
    cin >> a >> b >> res; ans = 0;
    if (res%gcd(a,b) != 0){
        cout << 0 << '\n'; return;
    }
    int s = sqrt(res);
    fr(GCD, 1, s){
        if (res%GCD == 0){
            resh(GCD); 
            if (res / GCD != GCD) resh(res/GCD);
        }
    }
    cout << ans << "\n";
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

    
    fr(i, 2, maxn-1){
        if (!prime[i]){
            for(int j = i; j < maxn; j += i){
                d[j]++;
                prime[j] = 1;
            }
        }
    }
    
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