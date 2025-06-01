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
#define lc(S) ((S << 1) + 1)
#define rc(S) ((S << 1) + 2)
using ii = pair<int, int>;
using ic = pair<int, char>;
template <typename T>
using v = vector<T>;
using vi = v<int>;
using vii = v<ii>;
using vvi = v<vi>;
using vc = v<char>;
using vvc = v<vc>;
 
const int MOD = 1e9+7;
const int INF = 1e18;
const int maxn = 1e5+10;

int n;

bool parofper(vi& ans){
    vi visited(n, 0);
    int c = 0;
    fr(i, 0, n-1){
        if (!visited[i]){
            c++;
            int j = i;
            while(!visited[j]){
                visited[j] = 1;
                j = ans[j]-1;
            }
        }
    }
    return (n-c)%2;
}

bool check(bool c, vi& ans){
    if (c == parofper(ans)){
        fe(c, ans) cout << c << " ";
        cout << '\n';
        return 1;
    }
    return 0;
}

void solve(){
    cin >> n;
    vi a(n); fe(c, a) cin >> c;
    vi od, ev;
    fr(i, 0, n-1){
        if (i%2 == 1){
            od.pb(a[i]);
        }else{
            ev.pb(a[i]);
        }
    }
    vi ans(n);
    int i = 0, j = 0;
    sort(all(od));
    sort(all(ev));
    while(i + j < n-4){
        if (i >= j){
            ans[j+i] = ev[j];
            j++;
        }else{
            ans[j+i] = od[i];
            i++;
        }
    }
    vi b;
    while(i+j < n){
        if (i >= j){
            b.pb(ev[j]);
            j++;
        }else{
            b.pb(od[i]);
            i++;
        }
    }
    fr(i, 0, 3) ans[n-4+i] = b[i];
    v<bool> ch(4, 0);
    fr(j, 0, 3){
        fr(i, 0, n-1){
            if (a[i] == b[j]) break;
            if (a[i] > b[j]) ch[j] = !ch[j];
        }
    }
    ans[n-4] = b[0];
    ans[n-2] = b[2];
    bool c = parofper(a);
    if (check(c, ans)) return;
    swap(ans[n-3], ans[n-1]);
    if (check(c, ans)) return;
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    srand(time(NULL));
    clock_t t1,t2;
    t1=clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    int t; cin >> t;
    while(t--) solve();
 
    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms\n";
    #endif
    return 0;
}