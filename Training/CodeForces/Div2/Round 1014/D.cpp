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
const int INF = 1e18;
const int maxn = 1e5+10;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    unordered_map<char, int> r;
    fe(c, s) r[c]++;
    int k = 0;
    for(auto c : {'T', 'L', 'I'}) if (r[c] == 0) k++;
    if (k >= 2){
        cout << -1 << '\n';
        return;
    }
    vi opers;
    char fl = 'I', sl = 'T', tl = 'L';
    if (r[fl] < r[sl]) swap(fl, sl);
    if (r[fl] < r[tl]) swap(fl, tl);
    if (r[sl] < r[tl]) swap(sl, tl);
    // cout << char(fl) << " " << char(sl) << " " << char(tl) << '\n';
    while(opers.size() < 2*n && (r[fl] != r[sl] || r[fl] != r[tl])){
        bool f = 0;
        fr(i, 0, n-2){
            if (((s[i] == fl && s[i+1] == sl) || (s[i] == sl && s[i+1] == fl)) && r[tl] < r[fl]){
                s = s.substr(0, i+1) + tl + s.substr(i+1, 2*n);
                r[tl]++; n++; f = 1;
                opers.pb(i);
            }
            if (((s[i] == fl && s[i+1] == tl) || (s[i] == tl && s[i+1] == fl)) && r[sl] < r[fl]){
                s = s.substr(0, i+1) + sl + s.substr(i+1, 2*n);
                r[sl]++; n++; f = 1;
                opers.pb(i);
            }
        }
        if (f == 0){
            fr(i, 0, n-2){
                bool f = 0;
                if (((s[i] == tl && s[i+1] == sl) || (s[i] == sl && s[i+1] == tl))){
                    s = s.substr(0, i+1) + fl + s.substr(i+1, 2*n);
                    r[fl]++; n++; opers.pb(i);
                    break;
                }
            }
        }
    }
    // cout << r[fl] << " " << r[sl] << " " << r[tl] << '\n';
    // cout << s << " " << opers.size() << "\n";
    if (opers.size() <= 2*n && r[fl] == r[sl] && r[fl] == r[tl]){
        cout << opers.size() << '\n';
        fe(c, opers) cout << c+1 << "\n";
    }else{
        cout << -1 << '\n';
    }
    // cout << s << "\n";
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