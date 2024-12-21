#include<bits/stdc++.h>

using namespace std;
#define int long long int
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for(int caseN = 0; caseN < t; caseN++){
        int n; cin >> n;
        vi a(2*n), b(2*n);
        for(auto& c : a) cin >> c;
        for(auto& c : b) cin >> c;
        vector<pair<int, int>> s;
        for(int i = 0; i < 2*n; i++){
            s.push_back({abs(a[i] - b[i]), i});
        }
        sort(all(s));
        int c1 = 0, c2 = 0, ans = 0;
        for(int i = n*2-1; i >= 0; i--){
            int j = s[i].second;
            if ((a[j] > b[j] && c2 < n) || (c1>=n)){
                ans += b[j];
                c2++;
            }else{
                c1++;
                ans += a[j];
            }
            // cout << ans << endl;
        }
        cout << ans << endl;
    }
    return 0;
}