#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define fr(i, a, b) for(int i = (a); i <= (b); i++)
#define rf(i, a, b) for(int i = (a); i >= (b); i--)
#define fe(c, a) for(auto& c : a)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define mk(a, b) make_pair(a, b)
#define lc(i) ((i<<1)+1)
#define rc(i) ((i<<1)+2)
#define par(i) ((i-1)>>1)
#define LSone(i) (i & (-i))
template <typename T>
using v = vector<T>;
using ic = pair<int, char>;
using ii = pair<int, int>;

const int INF = 1e10;

struct segTree{
private:
    int size;
    struct node{
        int min;
        int val;
    };
    node neutral(){
        node r;
        r.min = 0, r.val = -1;
        return r;
    }
    v<node> st;
public:
    segTree(int n){
        size = 1;
        while(size < n) size<<=1;
        st.assign(2*size-1, neutral());
    }
    void propagate(int v, int lv, int rv){
        if (st[v].val != -1 && rv - lv != 1){
            int m = (rv+lv)/2;
            st[lc(v)].val = st[rc(v)].val = st[v].val;
            st[lc(v)].min = st[rc(v)].min = st[v].val;
            st[v].val = -1;
        }
    }
    void update(int l, int r, int x, int v, int lv, int rv){
        if (lv >= r || rv <= l) return;
        if (lv >= l && rv <= r) {
            st[v].val = x;
            st[v].min = x;
            return;
        }
        propagate(v, lv, rv);
        int m = (lv + rv)/2;
        update(l, r, x, lc(v), lv, m);
        update(l, r, x, rc(v), m, rv);
        st[v].min = min(st[lc(v)].min, st[rc(v)].min);
    }
    void update(int l, int r, int x){
        update(l, r, x, 0, 0, size);
    }
    int rmq(int l, int r, int v, int lv, int rv){
        if (lv >= r || rv <= l) return INF;
        if (lv >= l && rv <= r) return st[v].min;
        propagate(v, lv, rv);
        int m = (lv+rv)/2;
        return min(rmq(l, r, lc(v), lv, m), rmq(l, r, rc(v), m, rv));
    }
    int rmq(int l, int r){
        return rmq(l, r, 0, 0, size);
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, q; cin >> n >> q;
    segTree st(n);
    while(q--){
        int z; cin >> z;
        int l, r; cin >> l >> r;
        if (z == 1){
            int v; cin >> v;
            st.update(l, r, v);
        }else{
            cout << st.rmq(l, r) << "\n";
        }
    }

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