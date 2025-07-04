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
const int maxn = 2002;

int m, d; 
vi tenpow(maxn, 1);

int mult(int a, int b, int mod){
    return (a*b)%mod;
}
int sum(int a, int b, int mod){
    return (a+b)%mod;
}
int razn(int a, int b, int mod){
    if (b > a) return mod-b+a;
    return a-b;
}

int sol(string& a){
    int n = a.length();
    v<vvi> dp(n, vvi(m, vi(2, 0)));
    fr(x, 1, 9){
        if (x == d || x > (a[0]-'0')) continue;
        dp[0][(x*tenpow[n-1])%m][(x<(a[0]-'0'))] += 1;
    }
    fr(i, 1, n-1){
        fr(j, 0, m-1){
            if (dp[i-1][j][0] == 0 && dp[i-1][j][1] == 0) continue;
            fr(k, 0, 1){
                fr(x, 0, 9){
                    if ((i+1)%2 == 0) {
                        if (x != d) continue;
                    }else {
                        if (x == d) continue;
                    }
                    if (k == 1){
                        int& c = dp[i][(j+x*tenpow[n-1-i])%m][1];
                        c = sum(c, dp[i-1][j][k], MOD);
                    }else{
                        if (x > (a[i]-'0')) continue;
                        int& c = dp[i][(j+x*tenpow[n-1-i])%m][(x<(a[i]-'0'))];
                        c = sum(c, dp[i-1][j][k], MOD);
                    }
                }
            }
        }
    }
    return sum(dp[n-1][0][0], dp[n-1][0][1], MOD);
}

bool dmagic(string s){
    bool f = 0;
    int ost = 0, n = s.length();
    fr(i, 0, n-1){
        if (((i+1)%2 == 0 && (s[i]-'0') != d) || ((i+1)%2 == 1 && (s[i]-'0') == d)) return 0; 
        ost = (ost+(s[i]-'0')*tenpow[n-1-i])%m;
    }
    return (ost == 0);
}

void solve(){
    cin >> m >> d;
    fr(i,1,maxn-1)tenpow[i] = mult(tenpow[i-1], 10, m);
    string a, b; cin >> a >> b;
    cout << razn(sol(b), sol(a), MOD)+dmagic(a) << '\n';
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