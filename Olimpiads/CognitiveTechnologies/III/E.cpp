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

const int MOD = 998244353;
const int N = 2*1e5+2;
v<int> fact(N, 1); v<int> ifact(N, 1);
v<int> primes;

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

int subs(int a, int b){
    if (b <= a) return (a-b);
    return (MOD+a-b);
}

int mult(int a, int b){
    return (a*b)%MOD;
}

int lcm_of_list(const vector<int>& numbers) {
    return accumulate(numbers.begin(), numbers.end(), 1LL, mult);
}

int mod_pow(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int count_A1(int m, int n) {
    vector<bool> is_prime(m + 1, true);
    is_prime[0] = is_prime[1] = false;
    vector<int> primes;

    for (int i = 2; i <= m; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= m; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int total = 0;
    int k = primes.size();

    for (int subset_size = 1; subset_size <= k; ++subset_size) {
        vector<int> subset;
        for (int i = 0; i < (1 << k); ++i) {
            subset.clear();
            for (int j = 0; j < k; ++j) {
                if ((i >> j) & 1) {
                    subset.push_back(primes[j]);
                }
            }

            if (subset.size() != subset_size) {
                continue;
            }

            int  subset_lcm = lcm_of_list(subset);
            if (subset_lcm > m) {
                continue;
            }

            int count = mod_pow(m / subset_lcm, n, MOD);

            if (subset_size % 2 == 1) {
                total = (total + count) % MOD;
            } else {
                total = (total - count + MOD) % MOD;
            }
        }
    }

    return total;
}

int power(int m, int n){
    if (n == 0) return 1;
    int x = m;
    fr(i, 1, n-1){
        m = mult(m, x);
    }
    return m;
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    clock_t t1,t2;
    t1=clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t; cin >> t;
    fr(i, 1, N-1){
        fact[i] = (fact[i-1]*i)%MOD;
        ifact[i] = invers(fact[i]);
    }
    v<bool> vis(N,0);
    for(int i = 2; i < N; i++){
        if (!vis[i]) primes.push_back(i);
        for(int j = i*i; j < N; j+=i)
            vis[j] = 1;
    }
    // cout << power(4, 2);
    while(t--){
        int n, m; cin >> n >> m;
        int ans = power(m,n);
        ans = subs(ans, count_A1(m, n));
        // cout << ans << endl;
        // fe(p, primes){
        //     if (p > m) break;
        //     ans = subs(ans, power(m/p, n));
        // }
        // cout << ans << endl;
    }

    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms";
    #endif
    return 0;
}