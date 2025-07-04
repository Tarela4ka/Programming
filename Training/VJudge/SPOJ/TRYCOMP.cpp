#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops") 
 
using namespace std;
// #define int long long int
#define lll __int128_t
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rf(i, a, b) for (int i = (a); i >= (b); --i)
#define fe(tx, ty) for (auto& tx : ty)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
#define pb(b) push_back(b)
#define LSOne(S) (S & (-S))
#define lc(S) ((S << 1))
#define rc(S) ((S << 1) + 1)
// #define par(S) ((S << 1) + 2)
using ii = pair<int, int>;
using ic = pair<int, char>;
template <typename T>
using v = vector<T>;
using vi = v<int>;
using vii = v<ii>;
using vvii = v<vii>;
using vvi = v<vi>;
using vc = v<char>;
using vvc = v<vc>;
 
const int MOD = 1e9+7;
const int INF = 1e9;
const int maxn = 1e7+10;
const int maxm = 2e5+10;


struct Node{
    int a[26] = {};
    string s = ""; int am = 0;
    bool f = false;
};

int root = 0;
int Size = root+1;
v<Node> trie(Size); 

void add(string s, int p){
    int node = root;
    fe(c, s){
        if (trie[node].a[c-'a'] == 0){
            Node b;
            trie.pb(b);
            trie[node].a[c-'a'] = Size++;
        }
        node = trie[node].a[c-'a'];
        if (p > trie[node].am || (p == trie[node].am && s < trie[node].s)){
            trie[node].am = p;
            trie[node].s = s;           
        }
    }
    trie[node].f = 1;
}

pair<string, int> search(string& s){
    int node = root;
    fe(c, s){
        if (trie[node].a[c-'a'] == 0){
            return {"0", 0};
        }
        node = trie[node].a[c-'a'];
    }
    return mk(trie[node].s, trie[node].am);
}

void solve(){
    int n; cin >> n;
    map<string, int> r;
    while(n--){
        string s; cin >> s;
        r[s]++;
    }
    fe(c, r){
        // cout << c.first << " " << c.second << '\n';
        add(c.first, c.second);
    }
    int q; cin >> q;
    while(q--){
        string s; cin >> s;
        pair<string, int> ans = search(s);
        if (ans.second == 0) cout << -1 << '\n';
        else cout << ans.first << " " << ans.second << '\n'; 
    }
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    srand(time(NULL));
    #ifdef DEBUG
    clock_t t1,t2;
    t1=clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // int t; cin >> t;
    // while(t--) 
        solve();

    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms";
    #endif
    return 0;
}