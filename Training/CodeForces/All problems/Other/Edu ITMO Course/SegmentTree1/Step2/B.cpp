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

struct Fenwick{
private:
    int size;
    vi ft;
    int parent(int i){
        return i+LSOne(i);
    }
    int child(int i){
        return i-LSOne(i);
    }
public: 
    void init(int n) { size = n; ft.assign(size+1, 0); }
    Fenwick(int n){ init(n); }
    void add(int i, int val){
        for(; i <= size; i = parent(i)) ft[i]+=val;
    }
    int rsq(int i){
        int res = 0;
        for(; i; i = child(i)) res += ft[i];
        return res;
    }
    int rsq(int l, int r){
        return rsq(r)-rsq(l-1);
    }
    int select(int k){
        int l = 0, r = size+1;
        while(r - l > 1){
            int mid = (l+r)/2;
            if (rsq(mid) >= k) r = mid;
            else l = mid;
        }
        return r-1;
    }
    void print(){
        cout << size << "\n";
        fr(i, 1, size) cout << ft[i] << " ";
        cout << endl;
    }
};

struct Segment{
private:
    int size;
    vi st;  
    int lc(int i){
        return ((i<<1) + 1);
    }
    int rc(int i){
        return ((i<<1) + 2);
    }
    int par(int i){
        return ((i-1)>>1);
    }
    int conquer(int a, int b){
        return a+b;
    }
    void set(int i){
        if (i < 0) return;
        st[i] = conquer(st[lc(i)], st[rc(i)]);
        set(par(i));
    }
public:
    void init(int n){
        size = 1;
        while(size < n) size<<=1;
        st.assign(2*size-1, 0);
    }
    Segment(int n){init(n); }
    void set(int i, int val){
        i += size-1;
        st[i] = val;
        set(par(i));
    }
    int select(int k, int v){
        if (v >= size-1) return v-size+1;
        if (st[lc(v)] > k) return select(k, lc(v));
        return select(k-st[lc(v)], rc(v));
    }
    int select(int k){
        return select(k, 0);
    }
    void print(){
        cout << 2*size-1 << "\n";
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

    int n, q; cin >> n >> q;
    bool F = 1, S = 0;
    if (F){
        Fenwick ft(n);
        vi a(n+1);
        fr(i, 1, n){
            int x; cin >> x;
            a[i] = x;
            ft.add(i, x);
        }
        fr(i, 1, q){
            int z, k; cin >> z >> k;
            k++;
            if (z == 1){
                int c; 
                if (a[k] == 0) c = 1;
                else c = -1; 
                a[k] += c;
                ft.add(k, c);
            } else {
                cout << ft.select(k) << "\n";
            }
        } 
    }
    
    if (S){
        Segment st(n);
        vi a(n);
        fr(i, 0, n-1){
            int x; cin >> x;
            a[i] = x;
            st.set(i, x);
        }
        // st.print();
        fr(i, 1, q){
            int z, k; cin >> z >> k;
            if (z == 1){
                a[k] = !a[k];
                st.set(k, a[k]);
                // st.print();
            }else{
                // k++;
                cout << st.select(k) << "\n";
            }
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