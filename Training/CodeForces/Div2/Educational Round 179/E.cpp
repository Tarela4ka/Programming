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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    map<char, map<char, int>> r;
    int bca = 0, cba = 0;
    for(int j = 0; j < m; j++){
        char x, y; cin >> x >> y; 
        if (x == 'a') continue;
        r[x][y]++;
        if (x == 'c' && y == 'a'){
            if (r['b']['c'] > 0) {
                r['c']['a']--; r['b']['c']--; bca++;
            }
        }
        if (x == 'b' && y == 'a'){
            if (r['c']['b'] > 0){
                r['c']['b']--; r['b']['a']--; cba++;
            }
        }
    }
    fr(i, 0, n-1){
        if (s[i] == 'a'){
            cout << 'a';
        }
        if (s[i] == 'b'){
            if (r['b']['a'] > 0){
                r['b']['a']--; 
                cout << 'a';
            }else if (cba > 0){
                cba--; r['c']['b']++;
                cout << 'a';
            }else if (bca > 0){
                bca--;
                cout << 'a';
            }else{
                cout << 'b';
            }
        }
        if (s[i] == 'c'){
            if (r['c']['a'] > 0){
                r['c']['a']--; 
                cout << 'a';
            }else if (bca > 0){
                bca--; r['b']['c']++;
                cout << 'a';
            }else if (cba > 0){
                cba--; 
                cout << 'a';
            }else if (r['c']['b'] > 0){
                r['c']['b']--;
                cout << 'b';
            }else{
                cout << "c";
            }
        }
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
    cout << '\n' << diff << "ms";
    #endif
    return 0;
}