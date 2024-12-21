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
    int n; cin >> n;
    vi a(n); for(auto& c : a) cin >> c;
    auto it = a.begin()-1;
    int ans = 0;
    while(it != a.end()-1){
        auto m = max_element(it+1, a.end());
        int x = 0;
        for(auto i = it+1; i <= m; i++, x++);
        // cout << x << " " << *m << endl;
        ans+=x*(*m);
        it = m;
    }
    cout << ans;
    return 0;
}