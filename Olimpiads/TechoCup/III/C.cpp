#include<bits/stdc++.h>

using namespace std;
#define int long long int
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
using ii = pair<int, int>;

const int MOD = 1e9+7;

int mult(int a, int b) { 
    return 1LL * a * b % MOD; 
}

int bpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = mult(res, a);
        }
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int x) {
    return bpow(x, MOD - 2);
}

int sub(int a, int b){
    if (b > a) return MOD+a-b;
    return a-b;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    clock_t t1,t2;
    t1=clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, t, k; cin >> n >> t >> k;
    if (t == 0){
        cout << sub(bpow(2, n*k)-1, bpow(2, n*(k-1))-1);
    }
    if (t == 1){
        k--;
        cout << mult( mult( bpow(2, n*n)-1, bpow(2, k) ), inv(bpow(2, n) - 1) );
    }
    if (t == 2){
        if (k == 2)
            cout << (mult(bpow(2, (n-1)*(n+1))-1, inv(bpow(2, n-1)-1)))-1;
        else 
            cout << mult(bpow(2, (n+1)*n)-1, inv(bpow(2, n+1)-1));
    }

    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms";
    #endif
    return 0;
}