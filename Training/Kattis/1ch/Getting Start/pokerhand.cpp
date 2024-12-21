#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    map<char, int> r;
    for(; cin >> s; ) r[s[0]]++;
    int maxV = 0;
    for(auto [k, v] : r) maxV = max(maxV, v);
    cout << maxV;
    return 0;
}

