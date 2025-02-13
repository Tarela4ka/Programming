#include<bits/stdc++.h>

using namespace std;
#define int long long
#define lll __int128_t
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rf(i, a, b) for (int i = (a); i >= (b); --i)
#define fe(x, y) for (auto& x : y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
using ii = pair<int, int>;
using ic = pair<int, char>;
template <typename T>
using v = vector<T>;
using vi = v<int>;
using vii = v<ii>;
using vvi = v<vi>;

const int MOD = 998244353;
const int INF = 1e14+10;
const int maxn = 1e6+10;

vi dels;

struct segtree{
private:
    int size;
    struct node{
        int sum, max;
    };
    node neutral(){
        node r;
        r.sum = r.max = 0;
        return r;
    };
    node merge(node a, node b){
        a.max = max(a.max, b.max);
        a.sum = a.sum + b.sum;
        return a;
    }
    int lc(int v){
        return (v<<1)+1;
    }
    int rc(int v){
        return (v<<1)+2;
    }
    int par(int v){
        return ((v-1)>>1);
    }
    v<node> st;
    void build(vi& a, int v, int lv, int rv){
        if (rv-lv == 1){
            if (lv < a.size()){
                st[v].max = st[v].sum = a[lv];
            }
            return;
        }
        int m = (lv + rv)/2;
        build(a, lc(v), lv, m);
        build(a, rc(v), m, rv); 
        st[v] = merge(st[lc(v)], st[rc(v)]);
    }
    node req(int l, int r, int v, int lv, int rv){
        if (lv >= r || rv <= l) return neutral();
        if (lv >= l && rv <= r) return st[v];
        int m = (lv + rv)/2;

        return merge(
            req(l, r, lc(v), lv, m),
            req(l, r, rc(v), m, rv)
        );
    }
    void upd(int l, int r, int v, int lv, int rv){
        if (lv >= r || rv <= l) return;
        if (lv >= l && rv <= r) {
            if (st[v].max <= 2) 
                return;
            if (rv-lv == 1) {
                st[v].max = st[v].sum = dels[st[v].sum];
                return;
            }
        }
        
        int m = (lv + rv)/2;
        upd(l, r, lc(v), lv, m);
        upd(l, r, rc(v), m, rv); 
        st[v] = merge(st[lc(v)], st[rc(v)]);
    }
public:
    void init(int n){
        size = 1;
        while(size < n) size<<=1;
        st.assign(2*size-1, neutral());
    }
    segtree(vi a){
        init(a.size()+1);
        build(a, 0, 0, size);
    }
    int req(int l, int r){
        return req(l, r, 0, 0, size).sum;
    }
    void upd(int l, int r){
        upd(l, r, 0, 0, size);
    }
};

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    clock_t t1,t2;
    t1=clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vi sieve(maxn, 0);
    dels.resize(maxn, 0);
    dels[1] = dels[0] = 1;
    fr(i, 2, maxn-1){
        dels[i]++;
        for(int j = i; j < maxn; j+=i)
            dels[j]++;
    }
    int n, q; cin >> n >> q;
    vi a(n); fe(c, a) cin >> c;
    segtree st(a);
    while(q--){
        int t, l, r;
        cin >> t >> l >> r; l--;
        if (t == 1){
            st.upd(l, r);
        }else{
            cout << st.req(l, r) << endl;
        }
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