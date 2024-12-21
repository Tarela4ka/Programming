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

const int N = 1e6+20;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int l,r; cin >> l >> r;

    vi s(N, 1); s[0] = s[1] = 0;
    for(int i = 2; i < N; i++){
        if (!s[i]) continue;
        for(int j = 2*i; j < N; j+=i){
            s[j] = 0;
        }
    }
    bool f = true;
    for(int i = l; i <= r; i++){
        if (s[i] == 1) {
            f = false;
            cout << i << endl;
        }
    }
    if (f) cout << "Absent";
    return 0;
}