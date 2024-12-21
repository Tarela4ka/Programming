#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    string s1, s2;
    getline(cin, s1);
    while(t--){
        getline(cin, s1);
        getline(cin, s2);
        // cout << s1 << '\n' << s2 << endl;

        bool f = 0;
        int ans = s1.length() + s2.length(), c = 0;
        if (s1[0] == s2[0]) f = 1;
        for(; c < min(s1.length(),s2.length()) && s1[c] == s2[c]; c++);
        ans -= c; ans += f;
        cout << ans << '\n';
    }
}