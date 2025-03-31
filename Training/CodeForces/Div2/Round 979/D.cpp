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

vi pers;
set<int> badpers;
string s;
vi sufmin, prmax;

void delper(int i){
    pers[i] = 0;
    badpers.erase(i);
}
void addper(int i){
    pers[i] = 1;
    // cout << i << " " << sufmin[i+1] << " " << prmax[i] << "\n";
    if (sufmin[i+1] < i+1 || prmax[i] > i+1) badpers.insert(i);
}

void solve(){
    int n, q; cin >> n >> q;
    vi a(n); fe(c, a) cin >> c;
    cin >> s;
    prmax.assign(n, 0); sufmin.assign(n, 0);
    prmax[0] = a[0]; sufmin[n-1] = a[n-1];
    fr(i, 1, n-1) prmax[i] = max(prmax[i-1], a[i]);
    rf(i, n-2, 0) sufmin[i] = min(sufmin[i+1], a[i]);
    pers.assign(n, 0);
    badpers.clear();
    fr(i, 0, n-2){
        if (s[i] == 'L' && s[i+1] == 'R'){
            addper(i);
        }
    }
    // fe(c, badpers) cout << c << " ";
    
    while(q--){
        int x; cin >> x; x--;
        if (s[x] == 'L') s[x] = 'R';
        else s[x] = 'L';
        if (s[x-1] == 'L'){
            if (s[x] == 'L'){
                delper(x-1);
                if (s[x+1] == 'R') addper(x);
            }else{
                addper(x-1);
                if (s[x+1] == 'R') delper(x);
            }
        }else{
            if (s[x+1] == 'R'){
                if (s[x] == 'L') addper(x);
                else delper(x);
            }
        }
        if (badpers.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
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