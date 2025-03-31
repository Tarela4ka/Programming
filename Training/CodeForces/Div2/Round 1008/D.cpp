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
const int maxa = 90;

int n;
v<pair<pair<char, int>, pair<char, int>>> vors, vors2;
v<int> memo;

int P(int c, int l, int r){
    if (c == n) return l+r;
    if (memo[c] > l + r) return 0;
    else memo[c] = l + r;
    auto [v1, v2] = vors2[c];
    int a1 = 0, a2 = 0;
    int res = 0;
    if (v1.first == '+') a1 = v1.second;
    else a1 = l*(v1.second-1);
    if (v2.first == '+') a2 = v2.second;
    else a2 = r*(v2.second-1);
    if (c == n-1){
        return l+r+a1+a2;
    }
    
    if (vors2[c+1].first.first == 'x' && vors2[c+1].second.first == '+')
        return P(c+1, l+a1+a2, r);
    if (vors2[c+1].first.first == '+' && vors2[c+1].second.first == 'x')
        return P(c+1, l, r+a2+a1);
    if (vors2[c+1].first.first == 'x' && vors2[c+1].first.first == 'x'){
        if (vors2[c+1].first.second > vors2[c+1].second.second)
            return P(c+1, l+a1+a2, r);
        else if (vors2[c+1].first.second < vors2[c+1].second.second)
            return P(c+1, l, r+a2+a1);
    }
    return max(P(c+1, l, r+a2+a1), P(c+1, l+a1+a2, r));
}
 
void solve(){
    cin >> n;
    vors.resize(n);
    vors2.clear();
    fe(c, vors){
        cin >> c.first.first >> c.first.second >> c.second.first >> c.second.second;
    }
    fr(i, 0, n-1){
        auto [v1, v2] = vors[i];
        if (v1.first == v2.first && v1.first == '+'){
            int c1 = 0, c2 = 0;
            while(i < n && (vors[i].first.first == vors[i].second.first && vors[i].first.first == '+')){
                c1 += vors[i].first.second;
                c2 += vors[i].second.second;
                i++;
            }
            vors2.pb(mk(mk('+', c1), mk('+', c2)));
            i--;
        }
        else if ((vors[i].first.first == vors[i].second.first && vors[i].first.first == 'x' && vors[i].first.second == vors[i].second.second)){
            int c1 = 1, c2 = 1;
            while(i < n && (vors[i].first.first == vors[i].second.first && vors[i].first.first == 'x' && vors[i].first.second == vors[i].second.second)){
                c1 *= vors[i].first.second;
                c2 *= vors[i].second.second;
                i++;
            }
            vors2.pb(mk(mk('x', c1), mk('x', c2)));
            i--;
        }else vors2.pb(vors[i]);
    }
    n = vors2.size();
    memo.clear(); memo.resize(n, 0);
    cout << P(0, 1, 1) << "\n";
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