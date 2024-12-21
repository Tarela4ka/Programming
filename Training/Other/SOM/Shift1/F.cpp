#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    for(auto& c : s) cin >> c;

    unordered_map<char, int> r;
    for(auto t : s)
        for(auto c : t)
            r[c]++;
    int maxK = 0;
    for(auto [c, k] : r)
        if (k > maxK)
            maxK = k;
    vector<char> l;
    for(auto [c, k] : r)
        if (k == maxK) l.push_back(c); 

    int ans = n;
    for(auto t : s){
        bool f = false;
        for(auto c : t){
            for(auto a : l){
                if (c == a){
                    f = true;
                    break;
                }
            }
            if (f) break;
        }
        ans -= f;
    }
    cout << ans;
    return 0;
}