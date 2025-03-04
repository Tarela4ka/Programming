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

void deleteinters(vi& a, vi& b){
    int i = 0, j = 0;
    vi newa, newb;
    while(i < a.size() && j < b.size()){
        if (a[i] < b[j]){
            newa.pb(a[i]);i++; 
        }else if (b[j] < a[i]){
            newb.pb(b[j]);j++; 
        }else{
            i++, j++;
        }
    }
    for(; i < a.size(); i++) newa.pb(a[i]);
    for(; j < b.size(); j++) newb.pb(b[j]);
    a = newa;
    b = newb;
}

void razl(vi& b){
    vi newb; vi q;
    fr(i, 0, (int)b.size()-1){
        if (b[i] == 1) newb.pb(1);
        else{
            if (b[i] != b[i+1] && !q.empty()){
                fr(j, 0, q.size()) newb.pb(q[0]/2);
                fr(j, 0, q.size()) newb.pb(q[0]/2+1);
                q.clear();
                continue;
            }
            if (b[i] % 2 == 0){
                newb.pb(b[i]/2);
                newb.pb(b[i]/2);
            }else{
                if (b[i+1] == b[i]){
                    q.pb(b[i]);
                }else{
                    newb.pb(b[i]/2);
                    newb.pb(b[i]/2+1);
                }
            }
        }
    }
    if (!q.empty()){
        fr(j, 0, q.size()-1) newb.pb(q[0]/2);
        fr(j, 0, q.size()-1) newb.pb(q[0]/2+1);
    }
    b = newb;
}

void solve(){
    int n, m; cin >> n >> m;
    vi a(n), b(m); 
    fe(c, a) cin >> c;
    fe(c, b) cin >> c;
    sort(all(a)); sort(all(b));
    deleteinters(a,b);
    while(!(a.empty() || b.empty())){
        int p = b.size();
        razl(b);
        if (b.size() == p || b.size() > a.size()){
            cout << "NO\n";
            return;
        }
        deleteinters(a,b);
    }
    if (a.empty() && b.empty()){
        cout << "YES\n";
    }else{
        cout << "NO\n";
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
    // vi a{1,1,3,3}, b{3, 5};
    // deleteinters(a,b);
    // fe(c, a) cout << c << " ";
    // cout << '\n';
    // razl(b);
    // fe(c, b) cout << c << " ";
    // cout << '\n';

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