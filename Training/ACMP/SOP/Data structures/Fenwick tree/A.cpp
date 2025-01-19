#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define fr(i, a, b) for(int i = (a); i <= (b); i++)
#define rf(i, a, b) for(int i = (a); i >= (b); i--)
#define fe(c, a) for(auto& c : a)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define mk(a, b) make_pair(a, b)
template <typename T>
using v = vector<T>;
using ic = pair<int, char>;
using ii = pair<int, int>;

int LSone(int i){
    return (i & (-i));
}

class FenwickTree{
private: 
    v<int> ft;
    int m;
public:  
    FenwickTree(int n) { m = n; ft.resize(m+1, 0); };
    void build(v<int> a){
        m = a.size()+1;
        ft.resize(m+1, 0);
        fr(i, 1, m){
            ft[i] += a[i];
            if (i+LSone(i) <= m) ft[i+LSone(i)] += ft[i];
        }
    }
    void update(int l, int r, int v){
        update(l, v);
        update(r+1, -v);
    }
    void update(int i, int v){
        for(; i <= m; i += LSone(i))
            ft[i] += v;
    }
    int rsq(int i){
        int res = 0;
        for(; i; i-=LSone(i)){
            res+=ft[i];
        }
        return res;
    }
    int rsq(int i, int j){
        return rsq(j)-rsq(i-1);
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
    FenwickTree f(n);
    while(q--){
        string z; int l, r;
        cin >> z >> l >> r;
        if (z == "rsq"){
            cout << f.rsq(l, r) << endl;
        }
        if (z == "add"){
            f.update(l, r);
        }
    }
    return 0;
}