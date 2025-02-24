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
using ii = pair<int, int>;
using ic = pair<int, char>;
template <typename T>
using v = vector<T>;
using vi = v<int>;
using vvi = v<vi>;

const int INF = 1e9+10;

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    clock_t t1,t2;
    t1=clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, k; cin >> n >> k;
    vi a(n); fe(c, a) cin >> c;
    unordered_map<int, vi> m;
    fr(i, 0, n-1){
        m[a[i]].push_back(i);
    }
    ii ans = mk(-1, 0);
    fe(c, m){
        int res = 1;
        vi& b = c.second;
        int p = b[0];
        fr(i, 1, (int)b.size()-1){
            if (b[i] > p+k){
                p = b[i];
                res++;
            }
        }
        if (res > ans.second){
            ans.first = c.first;
            ans.second = res;
        }
    }
    cout << ans.first << " " << ans.second;

    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms\n";
    #endif
}