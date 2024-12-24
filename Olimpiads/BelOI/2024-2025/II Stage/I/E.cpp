#include<bits/stdc++.h>

using namespace std;
#define int long long int
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rf(i, a, b) for (int i = (a); i >= (b); --i)
#define fe(x, y) for (auto& x : y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
using ii = pair<int, int>;
template <typename T>
using v = vector<T>;

const int MOD = 1e9+7;
const int INF = 1e9;

int invers(int n){
    int m = MOD-2;
    int res = 1;
    while(m){
        if(m&1){
            res = (res*n)%MOD;
        }
        n = (n*n) % MOD;
        m = m >> 1;
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n,k;
    cin >> n >> k;
    v<int> a(n);
    fe(c, a) cin >> c;
    v<int> bins(k+1, 1);
    v<int> fact(k+1, 1), ifact(k+1, 1);
    fr(i, 1, k){
        fact[i] = (fact[i-1]*i)%MOD;
        ifact[i] = invers(fact[i]);
    }
    fr(i, 1, k) bins[i] = (fact[k] * ((ifact[i]*ifact[k-i]) % MOD))%MOD;
    v<int> sum(n, 0);
    fr(i, 0, k){
        sum[i%n] = (sum[i%n]+bins[i])%MOD;
    }
    v<int> res(n, 0);
    fr(i, 0, n-1){
        fr(j, 0, n-1){
            int dist = j >= i ? j - i : n - i + j;
            res[j] = (res[j]+((a[i]*sum[dist])%MOD))%MOD;
        }
    }
    fe(c, res) cout << c << " ";
    return 0;
}