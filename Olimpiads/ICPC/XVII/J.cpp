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

const int INF = 1e18+10;
const int maxa = 1e6+10;
int col[maxa] = {};

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
    vvi fact(maxa); vi sieve(maxa, 0);
    fr(i, 2, maxa-1){
        if (!sieve[i])
        for(int j = i; j < maxa; j+=i){
            sieve[j] = 1;
            fact[j].push_back(i);
        }
    }
    fe(c, a){
        int m = fact[c].size();
        for(int mask = 1; mask < (1<<fact[c].size()); mask++){
            int res = 1;
            fr(i, 0, m-1){
                if (mask & (1<<i)) res*=fact[c][i];
            }
            col[res]++;
        }
    }
    int n1; bool ans = true;
    fr(j, 0, n-1){
        int m = fact[a[j]].size();
        int x = 0;
        for(int mask = 1; mask < (1<<fact[a[j]].size()); mask++){
            int res = 1, k = 0;
            fr(i, 0, m-1){
                if (mask & (1<<i)) {
                    res*=fact[a[j]][i];
                    k++;
                }
            }
            if (k%2 == 1) x+=col[res];
            else x-=col[res];
        }
        if (x != n){
            ans = false;
            n1 = a[j];
        }
    }
    if (ans){
        cout << "YES";
        return 0;
    }
    fr(j, 0, n-1){
        if (gcd(n1, a[j]) == 1){
            cout << "NO\n";
            cout << n1 << " " << a[j] << "\n";
            return 0;
        }
    }

    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms\n";
    #endif
}