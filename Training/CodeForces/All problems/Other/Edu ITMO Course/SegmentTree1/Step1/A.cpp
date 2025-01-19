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

const int MOD = 1e9+7;
const int INF = 1e10;

struct segmentTree{
private:
    vi st;
    int size;
    int lc(int x) {
        return ((x<<1)+1);
    }
    int rc(int x) {
        return ((x<<1)+2);
    }
    int par(int x) {
        return ((x-1)>>1);
    }
public:
    void init(int n){
        size = 1;
        while(size < n) size<<=1;
        st.resize(2*size-1, 0);
    }
    void set(int x){
        if (x < 0) return;
        st[x] = st[lc(x)]+st[rc(x)];
        set(par(x));
    }
    void set(int i, int v){
        i = size+i-1;
        st[i] = v; set(par(i));
    }
    int sum(int& l, int& r, int v, int lv, int rv){
        if (lv >= r || rv <= l) return 0;
        if (rv <= r && lv >= l) return st[v];
        int mid = (lv+rv)/2;
        return sum(l, r, lc(v), lv, mid) + sum(l, r, rc(v), mid, rv);
    }
    int sum(int l, int r){
        return sum(l, r, 0, 0, size);
    }
    void print(){
        cout << 2*size-1 << endl;
        fe(c, st) cout << c << " ";
        cout << endl;
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

    int n,q; cin >> n >> q;
    segmentTree st;
    st.init(n);
    fr(i, 0, n-1){
        int x; cin >> x;
        st.set(i, x);
    }
    fr(i, 0, q-1){
        int z, l, r;
        cin >> z >> l >> r;
        if (z == 1){
            st.set(l, r);
        }else{
            cout << st.sum(l, r) << "\n";
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