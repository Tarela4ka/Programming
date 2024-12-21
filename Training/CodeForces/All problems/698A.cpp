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
    int n; cin >> n;
    vi a(n); 
    vi vis(n+1, 0);
    int ans = 0;
    for(auto& c : a) cin >> c;
    for(int i = 0; i < n; i++){
        if (a[i] == 0) ans++;
        if (a[i] == 1 && vis[i] != 1) vis[i+1] = 1;
        else if (a[i] == 1) ans++;
        if (a[i] == 2 && vis[i] != 2) vis[i+1] = 2;
        else if (a[i] == 2) ans++;

        if (a[i] == 3){
            if (vis[i] == 0){
                int j = i;
                while (a[j] == 3) j++;
                if (j >= n) vis[i+1] = 1;
                else if ((j-i)%2 == 0) {
                    vis[i+1] = a[j];
                }else{
                    if (a[j] == 2) vis[i+1] = 1;
                    if (a[j] == 1) vis[i+1] = 2;
                }
            }
            if (vis[i] == 1) vis[i+1] = 2;
            if (vis[i] == 2) vis[i+1] = 1;
        }
    }
    cout << ans;
    return 0;
}