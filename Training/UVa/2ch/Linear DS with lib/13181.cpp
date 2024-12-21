#include<bits/stdc++.h>

using namespace std;
// #define int long long int
// #define all(a) a.begin(), a.end()

signed main(){
    string s;
    while(cin >> s){
        int maxS = 0, p = 0;
        for(auto c : s){
            if (c == 'X'){
                maxS = p;
                p = 0;
            }else{
                p++;
            }
        }
        int p1 = 0, p2 = 0;
        for(auto c : s){
            if (c == 'X') break;
            p1++;
        }
        for(int i = s.length()-1; i >= 0; i--){
            if (s[i] == 'X') break;
            p2++;
        }
        maxS = max((maxS-1)/2, max(p1-1, p2-1));
        cout << maxS << endl;
    }
    return 0;
}