#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    for(int caseN = 1; caseN <= t; caseN++){
        int n = 10;
        vector<string> ans;
        int maxE = 0;
        for(int i = 0; i < n; i++){
            string s; int c;
            cin >> s >> c;
            if (c > maxE) {
                ans.clear();
                maxE = c;
            }
            if (c == maxE) ans.push_back(s);
        }
        printf("Case #%d:\n", caseN);
        for(auto s : ans) cout << s << "\n";
    }
    return 0;
}