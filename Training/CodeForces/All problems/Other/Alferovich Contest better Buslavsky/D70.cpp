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

    int n; cin >> n;
    vi a(n); fe(c, a) cin >> c;
    int q; cin >> q;
    while(q--){
        int i, k; cin >> i >> k; i--;
        int res = 0;
        fr(j, i, n-1){
            int c = min(a[j], k);
            res += c*(j-i);
            a[j] -= c;
            k -= c;
        }
        if (k != 0){
            fr(j, 0, i){
                int c = min(a[j], k);
                res += c*(j-i+n);
                a[j] -= c;
                k -= c;
            }
        }
        cout << res << "\n";
    }

    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms\n";
    #endif
}