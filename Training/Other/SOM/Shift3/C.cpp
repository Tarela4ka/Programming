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

const int MOD = 1000000007;

int getPbyN(int n, int p){
    int ans = 0;
    int a = p;
    while(p <= n){
        ans += floor(n/p); 
        p *= a;
    }
    return ans;
}

int getMinN(int p, int c){
    int res = p;
    while(getPbyN(res, p) < c){
        res+=p;
    }
    return res;
}


signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    map<int, int> fact;
    int s = sqrt(n);
    fr(i,2,s){
        while(n%i == 0){
            fact[i]++;
            n /= i;
        }
    }
    if (n != 1) fact[n]++;

    int ans = 0;
    fe(x, fact){
        auto [p, c] = x;
        ans = max(ans, getMinN(p, c));
    }
    cout << ans;
    return 0;
}