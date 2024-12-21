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

const int MOD = 1e9;

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,m,l;
    cin >> n >> m;
    l = gcd(n,m);
    vector<int> fib(l+2, 0);
    fib[0] = 0, fib[1] = 1;
    fr(i, 2, l){
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    }
    cout << fib[l];
    return 0;
}