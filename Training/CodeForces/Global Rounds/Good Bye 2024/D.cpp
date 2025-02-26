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
const int maxp = 4e5+10;

int mult(int a, int b){
    return (a*b)%MOD;
}

int bin_pow(int n, int p){
    int res = 1;
    while(p){
        if(p&1) res = mult(res, n);
        p>>=1;
        n = mult(n, n);
    }
    return res;
}

int inv(int a){
    return bin_pow(a, MOD-2);
}

struct fenwick{
private:
    int m;
    vi ft;
public:
    void init(int n){
        m = n;
        ft.assign(m+1, 1);
    }
    void build(vi& a){
        init(a.size());
        fr(i, 1, m){
            ft[i] = mult(ft[i], a[i-1]);
            if (i + LSOne(i) <= m){
                ft[i+LSOne(i)] = mult(ft[i+LSOne(i)], ft[i]);
            }
        }
    }
    int prq(int l, int r){
        return mult(prq(r), inv(prq(l-1)));
    }
    int prq(int i){
        int res = 1;
        for(; i; i-=LSOne(i)){
            res = mult(res, ft[i]);
        }
        return res;
    }
    void upd(int i, int prev, int newe){
        int razd = inv(prev); 
        for(; i <= m; i+=LSOne(i)){
            ft[i] = mult(ft[i], razd);
            ft[i] = mult(ft[i], newe);
        }
    }
};

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
    while(t--){
        int n, q; cin >> n >> q;
        vi tra(n), trb(n), comb(n); 
        vii a(n), b(n); 
        fr(i, 0, n-1){
            cin >> a[i].first;
            a[i].second = i;
        }
        fr(i, 0, n-1){
            cin >> b[i].first;
            b[i].second = i;
        }
        sort(all(b)); sort(all(a));
        fr(i, 0, n-1) {
            trb[b[i].second] = i;
            tra[a[i].second] = i;
            comb[i] = min(a[i].first, b[i].first);
        }
        // fe(c, comb) cout << c << " ";
        // cout << '\n';
        fenwick ft; ft.build(comb);
        cout << ft.prq(1, n) << " ";
        while(q--){
            int o, x; cin >> o >> x; x--;
            if (o == 1){
                x = tra[x];
                int tx = (upper_bound(all(a), mk(a[x].first, INF))-1)-a.begin();
                swap(a[tx], a[x]);
                swap(tra[a[tx].second], tra[a[x].second]);
                x = tx;
                a[x].first++; int newe = min(a[x].first, b[x].first);
                ft.upd(x+1, comb[x], newe);
                comb[x] = newe;
            }
            if (o == 2){
                x = trb[x];
                int tx = (upper_bound(all(b), mk(b[x].first, INF))-1)-b.begin();
                swap(b[tx], b[x]);
                swap(trb[b[tx].second], trb[b[x].second]);
                x = tx;
                b[x].first++; int newe = min(a[x].first, b[x].first);
                ft.upd(x+1, comb[x], newe);
                comb[x] = newe;
            }
            cout << ft.prq(1, n) << " ";
        }
        cout << '\n';
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