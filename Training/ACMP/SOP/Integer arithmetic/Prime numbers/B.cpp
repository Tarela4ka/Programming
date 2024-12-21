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

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; 
    cin >> n;

    vi sieve(2*n+2, 1); 
    sieve[1] = 0; sieve[0] = 0; 

    for(int i = 2; i <= 2*n; i++){
        for(int j = 2*i; j <= 2*n; j+=i){
            sieve[j] = 0;
        }
    }

    int ans = 0;
    for(int i = n+1; i < 2*n; i++)
        ans += sieve[i];
    cout << ans;
    return 0;
}