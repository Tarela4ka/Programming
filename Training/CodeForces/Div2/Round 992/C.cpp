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

const int INF = 1e9;

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string s = "";
        k--;
        while(k){
            s += ((k&1)+'0');
            k>>=1;
        }
        // cout << s << endl;
        if (s.length() >= n) {
            cout << -1 << endl;
            continue;
        }
        while(s.length() < n-1) s+='0';
        reverse(all(s));
        // cout << s << endl;
        int L = 0, R = n-1;
        v<int> a(n, 0);
        int p = 1;
        fe(c, s){
            if (!(c-'0')){
                a[L] = p++;
                L++;
            }else{
                a[R] = p++;
                R--;
            }
        }
        fe(c, a) {
            if (c == 0) cout << n << " ";
            else cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}