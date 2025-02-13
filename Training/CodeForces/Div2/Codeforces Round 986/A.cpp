#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define fr(i, a, b) for(int i = (a); i <= (b); i++)
#define rf(i, a, b) for(int i = (a); i >= (b); i--)
#define fe(c, a) for(auto& c : a)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
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
        int n; cin >> n;
        int a, b; cin >> a >> b;
        string s; cin >> s;
        int x = 0, y = 0;
        bool f = false;
        fr(i, 0, 120){
            fe(c, s){
                if (c == 'N') y++;
                if (c == 'E') x++;
                if (c == 'S') y--;
                if (c == 'W') x--;
                if (x == a && y == b) f = true;
            }
            if (f) break;
        }
        if (f) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}