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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string n, m;
    int res = 0;
    cin >> n >> m;
    reverse(all(n));
    reverse(all(m));
    int p = 0;
    while(p < n.length()){
        res += (n[p]-'0')*pow(3, p);
        p++;
    }
    p = 0;
    while(p < m.length()){
        res += (m[p]-'0')*pow(3, p);
        p++;
    }
    cout << res;
    return 0;
}