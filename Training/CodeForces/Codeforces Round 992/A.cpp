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

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t; cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        v<int>a(n);
        fe(c, a) cin >> c;
        bool ans = 0;
        fr(i, 0, n-1){
            bool f = true;
            fr(j, 0, n-1){
                if (abs(a[i]-a[j]) % k == 0 && i != j){
                    f = false;
                }
            }
            if (f){
                cout << "YES\n" << i+1 << '\n';
                ans = 1;
                break;
            }
        }
        if (!ans) cout << "NO\n";
    }
    return 0;
}