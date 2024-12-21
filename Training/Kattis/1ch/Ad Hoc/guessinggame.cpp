#include<bits/stdc++.h>

using namespace std;
// #define int long long int
// #define all(a) a.begin(), a.end()

signed main(){
    int l = 0,r = 1e9;
    while(true){
        int n; string s;
        cin >> n; 
        if (n == 0) break;
        getline(cin, s); 
        getline(cin, s);
        // cout << s << endl;
        if (s == "too low") l = max(n, l);
        if (s == "too high") r = min(n, r);
        if (s == "right on"){
            if (n > l && n < r) cout << "Stan may be honest\n";
            else cout << "Stan is dishonest\n";
            l = 0; r = 1e9; 
        }
    }
    return 0;
}