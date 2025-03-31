#include<bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops")

using namespace std;
#define int long long int
#define lll __int128_t
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rf(i, a, b) for (int i = (a); i >= (b); --i)
#define fe(x, y) for (auto& x : y)
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
const int INF = 1e16;
const int maxn = 1e5+10;

int mult(int a, int b){
    return (a*b)%MOD;
}
int sum(int a, int b){
    return (a+b)%MOD;
}

int bin_pow(int n, int p){
    int res = 1;
    while(p){
        if (p&1) res = mult(res, n);
        p>>=1;
        n = mult(n, n);
    }
    return res;
}
int mlog(int x) {
    return 31 - __builtin_clz(x);
}

bool sr(int x1, int x2, int k){
    if (k >= 29) return 1;
    return (ceil((double)x1/x2) <= (1 << k));
}

void solve(){
    int n; cin >> n;
    vi a(n); fe(c, a) cin >> c;
    int k = 0;
    vi pr1(n+1); pr1[0] = 0;
    fr(i, 1, n) pr1[i] = pr1[i-1] + mlog(LSOne(a[i-1]));
    // vi pr2(n); pr2[0] = mlog(LSOne(a[0]));
    // fr(i, 1, n-1) pr2[i] = mlog(LSOne(a[i]));
    vi pref(n); pref[0] = (a[0]>>pr1[1]);
    fr(i, 1, n-1) pref[i] = pref[i-1] + (a[i]>>(pr1[i+1]-pr1[i]));

    // fe(c, pr1) cout << c << " ";
    // cout << '\n';
    // fe(c, pref) cout << c << " ";
    // cout << '\n';
    stack<ii> q; q.push(mk(0, a[0]));
    cout << a[0] << " ";
    fr(i, 1, n-1){
        int x = a[i], k = pr1[i];
        // cout << i << " " << x << " " << k << " " << pref[i-1] << " ";
        while(!q.empty() && sr(a[q.top().first], x, k-pr1[q.top().first])) q.pop();
        int res;
        if (q.empty()){
            // cout << pr1[i] << " " << a[i] << " " << pref[i-1] << '\n';
            res = sum(pref[i-1], mult(bin_pow(2, pr1[i]), a[i]) );
        }else{
            auto [j, r] = q.top();
            int nk = k-pr1[j+1];
            res = sum(r+pref[i-1]-pref[j], mult(bin_pow(2, nk), a[i]));
            // cout << "| " << j << " " << nk << " " << r << " ";
        }
        // cout << "\n" << res << "\n";
        cout << res << " ";
        q.push(mk(i, res));
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
    cout << '\n' << diff << "ms\n";
    #endif
    return 0;
}
// ⠀⢸⠂⠀⠀⠀⠘⣧⠀⠀⣟⠛⠲⢤⡀⠀⠀⣰⠏⠀⠀⠀⠀⠀⢹⡀
// ⠀⡿⠀⠀⠀⠀⠀⠈⢷⡀⢻⡀⠀⠀⠙⢦⣰⠏⠀⠀⠀⠀⠀⠀⢸⠀
// ⠀⡇⠀⠀⠀⠀⠀⠀⢀⣻⠞⠛⠀⠀⠀⠀⠻⠀⠀⠀⠀⠀⠀⠀⢸⠀
// ⠀⡇⠀⠀⠀⠀⠀⠀⠛⠓⠒⠓⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀
// ⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠀
// ⠀⢿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⠀⠀⢀⡟⠀
// ⠀⠘⣇⠀⠘⣿⠋⢹⠛⣿⡇⠀⠀⠀⠀⣿⣿⡇⠀⢳⠉⠀⣠⡾⠁⠀
// ⣦⣤⣽⣆⢀⡇⠀⢸⡇⣾⡇⠀⠀⠀⠀⣿⣿⡷⠀⢸⡇⠐⠛⠛⣿⠀
// ⠹⣦⠀⠀⠸⡇⠀⠸⣿⡿⠁⢀⡀⠀⠀⠿⠿⠃⠀⢸⠇⠀⢀⡾⠁⠀
// ⠀⠈⡿⢠⢶⣡⡄⠀⠀⠀⠀⠉⠁⠀⠀⠀⠀⠀⣴⣧⠆⠀⢻⡄⠀⠀
// ⠀⢸⠃⠀⠘⠉⠀⠀⠀⠠⣄⡴⠲⠶⠴⠃⠀⠀⠀⠉⡀⠀⠀⢻⡄⠀
// ⠀⠘⠒⠒⠻⢦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⠞⠛⠒⠛⠋⠁⠀
// ⠀⠀⠀⠀⠀⠀⠸⣟⠓⠒⠂⠀⠀⠀⠀⠀⠈⢷⡀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠙⣦⠀⠀⠀⠀⠀⠀⠀⠀⠈⢷⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⣼⣃⡀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣆⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠉⣹⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡆ Made by @Tarela4ka