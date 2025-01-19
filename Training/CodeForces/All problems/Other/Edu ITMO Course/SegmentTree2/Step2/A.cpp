#include<bits/stdc++.h>

using namespace std;
#define int long long int
#define lll __int128_t
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rf(i, a, b) for (int i = (a); i >= (b); --i)
#define fe(x, y) for (auto& x : y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
#define LSOne(S) (S & (-S))
template <typename T>
using v = vector<T>;
using ii = pair<int, int>;
using ic = pair<int, char>;
using vi = v<int>;

const int MOD = 1e9 + 7;
const int INF = 1e10;

struct segmentTree{
private:
    int size;
    struct node{
        int add = 0, min = 0;   
    };
    v<node> st;
    int lc(int i) { return ((i<<1)+1);}
    int rc(int i) { return ((i<<1)+2);}
    int par(int i) { return ((i-1)>>1);}
public:
    segmentTree(int n){
        size = 1;
        while(size < n) size <<= 1;
        st.resize(2*size-1);
    }
    void add(int l, int r, int x, int v, int lv, int rv){
        if (rv <= l || lv >= r) return;
        if (rv <= r && lv >= l) {
            st[v].add += x;
            st[v].min += x;
            return;
        }
        int m = (lv+rv)/2;
        add(l, r, x, lc(v), lv, m);
        add(l, r, x, rc(v), m, rv);
        st[v].min = min(st[lc(v)].min, st[rc(v)].min) + st[v].add;
    }
    void add(int l, int r, int v){
        add(l, r, v, 0, 0, size);
    }
    int rmq(int l, int r, int v, int lv, int rv){
        if (rv <= l || lv >= r) return INF;
        if (rv <= r && lv >= l) return st[v].min;

        int m = (lv+rv)/2;
        return min(rmq(l, r, lc(v), lv, m), rmq(l, r, rc(v), m, rv))+st[v].add;
    }
    int rmq(int l, int r){
        return rmq(l, r, 0, 0, size);
    }
};

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    clock_t timeStart,timeEnd;
    timeStart=clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, q; cin >> n >> q;
    segmentTree st(n);
    while(q--){
        int z; cin >> z;
        if (z == 1){
            int l, r, v;
            cin >> l >> r >> v;
            st.add(l, r, v);
        }else{
            int l, r; cin >> l >> r;
            cout << st.rmq(l, r) << "\n";
        }
    }

    #ifdef DEBUG
    timeEnd=clock();
    float diff (timeEnd-timeStart);
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