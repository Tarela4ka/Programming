#include<bits/stdc++.h>

using namespace std;
// #define int long long int
// #define all(a) a.begin(), a.end()

signed main(){
    int n;
    while(true){
        cin >> n;
        if (!n) break;
        vector<string> ans(n); 
        int p = -1;
        for(int i = 0; i < n; i++){
            string s1, s2;
            cin >> s1 >> s2;
            for(int i = 0; i < s2.length(); i++){
                p = (p+1)%n;
                while(ans[p] != "") p = (p+1)%n;
            }
            if (ans[p] == "") ans[p] = s1;
        }
        cout << ans[0];
        for(int i = 1; i < ans.size(); i++)
            cout << " " << ans[i];
        cout << endl;
    }
    return 0;
}