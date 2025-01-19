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
    int size;
    vi st;
    int lc(int i) { return ((i<<1)+1); }
    int rc(int i) { return ((i<<1)+2); }
    int par(int i) { return ((i-1)>>1); }
public:
    segmentTree(int n){
        size = 1;
        while(size < n) size<<=1;
        st.assign(size*2-1, 0);
    }
    void set(int i){
        if (i < 0) return;
        st[i] = st[lc(i)]+st[rc(i)];
        set(par(i));
    }
    void set(int i, int val){
        i+=size-1;
        st[i] = val;
        set(par(i));
    }
    int rsq(int l, int r, int v, int lv, int rv){
        if (lv >= l && rv <= r) return st[v];
        if (lv >= r || rv <= l) return 0;
        int m = (lv+rv)/2;
        return (rsq(l, r, lc(v), lv, m) + rsq(l, r, rc(v), m, rv));
    }
    int rsq(int l, int r){
        return rsq(l, r, 0, 0, size);
    }
    void print(){
        // cout << 2*size-1 << endl;
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
    
    int n; cin >> n; 
    vi a(2*n);
    fe(c, a) cin >> c;
    vi vis(n+1, -1), ans(n+1, 0);
    segmentTree st1(2*n);
    fr(i, 0, 2*n-1){
        int x = a[i];
        if (vis[x] == -1){
            vis[x] = i;
            st1.set(i, 1);
        }else{
            st1.set(vis[x], 0);
            ans[x] += st1.rsq(vis[x], i+1);
        }
    }
    segmentTree st2(2*n);
    vis.assign(n+1, -1);
    rf(i, 2*n-1, 0){
        int x = a[i];
        if (vis[x] == -1){
            vis[x] = i;
            st2.set(i, 1);
        }else{
            st2.set(vis[x], 0);
            ans[x] += st2.rsq(i, vis[x]+1);
        }
    }
    fr(i, 1, n) cout << ans[i] << " ";

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