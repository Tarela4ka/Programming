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
    string n; getline(cin, n);
    bool f = true; 
    char Max;
    fe(c, n){
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z'))){
            f = false;
        }
        Max = max(c, Max);
    }
    if (!f) cout << -1;
    else {
        if (Max >= '0' && Max <= '9'){
            cout << max(Max-'0'+1, 2);
        }else{
            cout << Max-'A'+11;
        }
    }
    return 0;
}