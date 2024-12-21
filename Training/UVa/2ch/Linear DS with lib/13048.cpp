#include<bits/stdc++.h>

using namespace std;

signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            bool f = false;
            if (s[i] == '-'){
                f = true;
                if (i+2 < s.length() && s[i+2] == 'B') f = false;
                if (i+1 < s.length() && (s[i+1] == 'B' || s[i+1] == 'S')) f = false;
                if (i-1 >= 0 && s[i-1] == 'S') f = false;
            }
            // if (f) cout << i << " ";
            ans+=f;
        }
        printf("Case %d: %d\n", i+1, ans);
    }
    return 0;
}