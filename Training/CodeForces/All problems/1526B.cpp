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
using vii = vector<ii>;
 
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        // if (n >= 1111) {
        //     cout << "YES\n";
        //     continue;
        // }
        if (n >= (n%11 * 111)) cout << "YES\n";
        else cout << "NO\n";
        
    }
    return 0;
}