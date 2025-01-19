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
        int cnt[42] = {};
        // int min; 
        // int max;
        int size;
        int res;
    };
    node neutral(){
        node res;
        // res.min = 0;
        // res.max = 41;
        res.res = 0;
        res.size = 1;
        return res;
    }
    v<node> st;
    int lc(int i){ return ((i<<1)+1);}
    int rc(int i){ return ((i<<1)+2);}
    int par(int i){ return ((i-1)>>1);}
    node conquer(node a, node b){
        node res;
        // res.min = min(a.min, b.min);
        // res.max = max(a.max, b.max);
        res.size = a.size+b.size;
        res.res = a.res+b.res;
        // if (a.min > b.max){
        //     res.res += a.size*b.size;
        // }else{
            fr(i, 1, 40){
                fr(j, i+1, 40)
                    res.res += b.cnt[i]*a.cnt[j];
            }  
        // }
        fr(i, 1, 40)
            res.cnt[i] += a.cnt[i]+b.cnt[i];
        return res;
    }
public:
    segmentTree(int n){
        size = 1;
        while(size < n) size<<=1;
        st.assign(2*size-1, neutral());
    }
    void set(int i){
        if (i < 0) return;
        st[i] = conquer(st[lc(i)], st[rc(i)]);
        set(par(i));
    }
    void set(int i, int val){
        i += size-1;
        st[i] = neutral();
        // st[i].min = st[i].max = val;
        st[i].cnt[val] = 1;
        set(par(i));
    }
    node inv(int l, int r, int v, int lv, int rv){
        if (lv >= r || rv <= l) return neutral();
        if (lv >= l && rv <= r) return st[v];
        int m = (lv+rv)/2;
        return conquer(inv(l, r, lc(v), lv, m), inv(l, r, rc(v), m, rv));
    }
    int inv(int l, int r){
        l--; return inv(l, r, 0, 0, size).res;
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
    segmentTree st(n+1);
    fr(i, 0, n-1){
        int x; cin >> x;
        st.set(i, x);
    }
    while(q--){
        int z; cin >> z;
        if (z == 1){
            int l, r; cin >> l >> r;
            cout << st.inv(l, r) << "\n";
        }
        if (z == 2){
            int i, x; cin >> i >> x;
            i--; st.set(i, x);
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