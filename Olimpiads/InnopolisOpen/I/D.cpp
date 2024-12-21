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

const int mod = 1e9+7;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, m;
    double alfa;
    cin >> n >> m >> alfa;
    vi l(n), r(n);
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i];
    int ans = 0;
    for(int bitmask = 0; bitmask < pow(2,n); bitmask++){
        int s1 = 0, s2 = 0;
        vi js; js.clear();
        for(int j = 0; j < n; j++){
            int bit = bitmask & (1 << j);
            if(bit == 0) {
                js.push_back(j);
            }else{
                s1 += l[j]; s2 += r[j];
            }
        }
        bool f1 = true, f2 = (s2 <= m);
        int i = 0;
        for(auto j : js) {
            // while(i < j){
            //     cout << "0";
            //     i++;
            // }
            // cout << "1";
            i++;
            if (m - s1 >= r[j]) f1 = false;
        }
        // while(i < n) {
        //     cout << "0"; i++;
        // }
        cout << endl;
        if (f1 && f2) ans++;
    }
    cout << ans%mod;
    return 0;
}