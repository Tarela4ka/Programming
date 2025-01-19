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
using vvi = v<vi>;

const int MOD = 1e9+7;
const int INF = 1e10;

class Fenwick{
private:
    int m;
    vi ft;
public:
    Fenwick(vi f){
        m = f.size();
        ft.resize(m+1, 0);
        fr(i, 1, m){
            ft[i] += f[i];
            if (i+LSOne(i) <= m) ft[i+LSOne(i)] += ft[i];
        }
    }
    int rsq(int i){
        int res = 0;
        for(; i; i-=LSOne(i)) res+=ft[i];
        return res;
    }
    void update(int i, int v){
        for(; i <= m; i += LSOne(i)) ft[i] += v;
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
    
    int n,m; cin >> n >> m;
    v<int> f(n+m, 0);
    v<int> s(n, 0);
    fr(i, 0, n-1) {
        f[i+m] = 1;
        s[i] = m+i;
    }
    Fenwick ft(f);
    fr(i, 0, m-1){
        int x; cin >> x;
        cout << ft.rsq(s[x-1]) << " ";
        if (i == m-1) break;
        ft.update(s[x-1], -1);
        s[x-1] = m-i-1;
        ft.update(s[x-1], 1);
    }
    cout << endl;


    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms\n";
    #endif
    return 0;
}