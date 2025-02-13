#include<bits/stdc++.h>

using namespace std;
#define int long long int
#define fr(i, k, b) for(int i = (k); i <= (b); i++)
#define rf(i, k, b) for(int i = (k); i >= (b); i--)
#define fe(c, k) for(auto& c : k)
#define all(k) (k).begin(), (k).end()
#define rall(k) (k).rbegin(), (k).rend()
template <typename T>
using v = vector<T>;
using vi = v<int>;
using vvi = v<vi>;
using ii = pair<int, int>;
using vii = v<ii>;

const int INF = 1e9;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t; cin >> t;
    while(t--){ 
        int n, k, b, myans; cin >> n >> k >> b;
        if (b >= n) myans = n;
        else if (k == 0) {
            myans = (b >= n ? n : n-1);
            if (b < n-2) myans = -1;
        }
        else myans = n-((n-1-b)/k+1);
        cout << myans << "\n";
    }
    return 0;
}