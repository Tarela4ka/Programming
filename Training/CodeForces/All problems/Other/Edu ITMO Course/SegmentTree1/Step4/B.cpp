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

int MOD;
const int INF = 1e10;

int sum(int a, int b){
    return (a+b)%MOD;
}

struct matrix{
    int table[2][2] = {};
    int mult(int a, int b){
        return (a*b)%MOD;
    }
    matrix mult(matrix b){
        matrix res;
        fr(r,0,1)fr(i, 0, 1)fr(j, 0, 1)
            res.table[i][j] = sum(res.table[i][j], mult(table[i][r], b.table[r][j]));
        return res;
    }
    void print(){
        fr(i, 0, 1) {
            fr(j, 0, 1) cout << table[i][j] << " ";
            cout << "\n";
        }
        cout << "\n";
    }
    void read(){
        fr(i, 0, 1) fr(j, 0, 1) cin >> table[i][j];
    }
};

struct segmentTree{
private:
    int size;
    v<matrix> st;
    matrix conquer(matrix a, matrix b){ return a.mult(b); };
    int lc(int i) {return ((i<<1)+1);};
    int rc(int i) {return ((i<<1)+2);};
    int par(int i) {return ((i-1)>>1);};
    matrix zero(){
        matrix res;
        fr(i, 0, 1) res.table[i][i] = 1;
        return res;
    }
public:
    segmentTree(int n) { 
        size = 1;
        while(size < n) size<<=1;
        st.assign(2*size-1, zero());
    }
    void set(int i){
        if (i < 0) return;
        st[i] = conquer(st[lc(i)], st[rc(i)]);
        set(par(i));
    }
    void set(int i, matrix val){
        i += size-1;
        st[i] = val;
        set(par(i));
    }
    matrix msq(int l, int r, int v, int lv, int rv){
        if (lv >= l && rv <= r) return st[v];
        if (lv >= r || rv <= l) return zero();
        int m = (lv+rv)/2;
        return conquer(msq(l, r, lc(v), lv, m), msq(l, r, rc(v), m, rv));
    }
    matrix msq(int l, int r){
        l--;
        return msq(l, r, 0, 0, size);
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

    int n, q;
    cin >> MOD >> n >> q;
    segmentTree st(n+1);
    fr(i, 0, n-1) {
        matrix t; t.read();
        st.set(i, t);
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        st.msq(l, r).print();
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