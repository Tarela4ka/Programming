#include<bits/stdc++.h>

using namespace std;
// #define int long long int
// #define all(a) a.begin(), a.end()

signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n; cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    map<char, int> r1, r2;
    for(auto c : s1) r1[c]++;
    for(auto c : s2) r2[c]++;
    int a1 = 0, a2 = 0;
    for(int i = 0; i < n; i++){
        if (s1[i] == s2[i]){
            r1[s1[i]]--;
            r2[s2[i]]--;
            a1++;
        }
    }
    for(auto c : s1){
        while(r1[c] && r2[c]){
            a2++;
            r1[c]--; r2[c]--;
        }
    }
    cout << a1 << " " << a2;
    return 0;
}