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

int mult(int a, int b){
    return (a*b)%MOD;
}
int sum(int a, int b){
    return (a+b)%MOD;
}

struct segmentTree{
private:
    int size;
    struct node{
        int mult = 1, sum = 0;
    };
    v<node> st;
    int lc(int i) { return ((i<<1)+1);}
    int rc(int i) { return ((i<<1)+2);}
    int par(int i) { return ((i-1)>>1);}
public:
    void set(int i){
        if (i < 0) return;
        st[i].sum = sum(st[lc(i)].sum, st[rc(i)].sum);
        set(par(i));
    }
    void set(int i, int v){
        i+=size-1;
        st[i].sum = v;
        set(par(i));
    }
    segmentTree(int n){
        size = 1;
        while(size < n) size <<= 1;
        st.resize(2*size-1);
        fr(i, 0, size-1) set(i, 1);
    }
    void update(int l, int r, int x, int v, int lv, int rv){
        if (lv >= r || rv <= l) return;
        if (lv >= l && rv <= r){
            st[v].mult = mult(st[v].mult, x);
            st[v].sum = mult(st[v].sum, x);
            return;
        }
        int m = (lv + rv)/2;
        update(l, r, x, lc(v), lv, m);
        update(l, r, x, rc(v), m, rv);
        st[v].sum = mult(sum(st[lc(v)].sum, st[rc(v)].sum), st[v].mult);
    }
    void update(int l, int r, int x){
        update(l, r, x, 0, 0, size);
    }
    int rsq(int l, int r, int mn, int v, int lv, int rv){
        if (lv >= r || rv <= l) return 0;
        if (lv >= l && rv <= r) return mult(mn, st[v].sum);

        int m = (lv + rv)/2;
        return 
                        sum(rsq(l, r, mult(mn, st[v].mult), lc(v), lv, m), 
                            rsq(l, r, mult(mn, st[v].mult), rc(v), m, rv));
    }
    int rsq(int l, int r){
        return rsq(l, r, 1, 0, 0, size);
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
            st.update(l, r, v);
        }else{
            int l, r; cin >> l >> r;
            cout << st.rsq(l, r) << "\n";
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