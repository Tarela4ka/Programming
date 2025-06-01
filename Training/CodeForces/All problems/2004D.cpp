#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
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
using ii = pair<int, int>;
using ic = pair<int, char>;
template <typename T>
using v = vector<T>;
using vi = v<int>;
using vii = v<ii>;
using vvi = v<vi>;
using vc = v<char>;
using vvc = v<vc>;

const int MOD = 998244353;
const int INF = 1e16;
const int maxn = 5e5+10;

v<string> a{"BG", "BR", "BY", "GR", "GY", "RY"};

void solve(){
    int n, q; cin >> n >> q;
    v<string> s(n);
    fe(c, s){
        cin >> c;
    }
    map<string, vi> pref, suf;
    fe(c, a){
        pref[c].assign(n, 0);
        suf[c].assign(n, 0);
    } 
    fe(c, a){
        int p = -1;
        fr(i, 0, n-1){
            if (s[i] == c) p = i;
            suf[c][i] = p;
        }
    }
    fe(c, a){
        int p = -1;
        rf(i, n-1, 0){
            if (s[i] == c) p = i;
            pref[c][i] = p;
        }
    }
    // fe(c, a){
    //     cout << c << ": \n";
    //     fr(i, 0, n-1){
    //         cout << pref[c][i] << " ";
    //     }
    //     cout << '\n';
    //     fr(i, 0, n-1){
    //         cout << suf[c][i] << " ";
    //     }
    //     cout << '\n';
    // }
    while(q--){
        int x, y; cin >> x >> y; x--; y--;
        if (s[x][0] == s[y][0] || s[x][0] == s[y][1] || s[x][1] == s[y][0] || s[x][1] == s[y][1]){
            cout << abs(x-y) << '\n'; continue;
        }
        int ans = INF;
        fe(c, a){
            if (c != s[x] && c != s[y]){
                // cout << c << " " << pref[c][x] << " " << suf[c][y] << endl;
                if (pref[c][x] != -1){
                    ans = min(ans, abs(pref[c][x]-x) + abs(pref[c][x]-y));
                }
                if (suf[c][y] != -1){
                    ans = min(ans, abs(suf[c][y]-x) + abs(suf[c][y]-y));
                }
                if (suf[c][x] != -1){
                    ans = min(ans, abs(suf[c][x]-x) + abs(suf[c][x]-y));
                }
                if (pref[c][y] != -1){
                    ans = min(ans, abs(pref[c][x]-x) + abs(pref[c][x]-y));
                }
            }
        }
        if (ans == INF) cout << -1 << '\n';
        else cout << ans << '\n';
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