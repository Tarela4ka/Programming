#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops") 
 
using namespace std;
#define int long long int
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
    int am = 0;
    bool f = false;
};

int root = 0;
int Size = root+1;
v<Node> trie(Size); 

void add(string s){
    int node = root;
    fe(c, s){
        if (trie[node].a[c-'a'] == 0){
            Node b;
            trie.pb(b);
            trie[node].a[c-'a'] = Size++;
        }
        node = trie[node].a[c-'a'];
        trie[node].am++;
    }
    trie[node].f = 1;
}

int search(string s){
    int node = root;
    fe(c, s){
        if (trie[node].a[c-'a'] == 0){
            return 0;
        }
        node = trie[node].a[c-'a'];
    }
    return trie[node].am;
}

void solve(){
    int n, q; cin >> n >> q;
    while(n--){
        string s; cin >> s;
        add(s);
    }
    while(q--){
        string s; cin >> s;
        cout << search(s) << '\n'; 
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