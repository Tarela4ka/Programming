#include<bits/stdc++.h>

using namespace std;
// #define int long long int
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()

const int N = 1e6+3;

signed main(){
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    vector<int> primes;
    vector<int> vis(N, 0);
    for(int i = 2; i < N; i++){
        if (vis[i] == 0){
            primes.push_back(i);
            for(int j = i; j < N; j+=i) vis[j] = 1;
        }
    }
    int ans = 1;
    for(auto p : primes){
        if (p > N/ans) break;
        int res; int c = p;
        cout << "? " << c << " " << 0 << endl;
        cin >> res;
        while(res == 1){
            c*=p;
            cout << "? " << c << " " << 0 << endl;
            cin >> res;
        }
        c/=p;
        ans *= c;
    }
    cout << "! " << ans;
    return 0;
}