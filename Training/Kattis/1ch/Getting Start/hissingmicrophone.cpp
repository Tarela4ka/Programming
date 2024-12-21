#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    bool ans = false;
    for(int i = 1; i < s.length(); i++){
        if (s[i] == s[i-1] && s[i] == 's') ans = true;
    }
    if (!ans) cout << "no ";
    cout << "hiss";
    return 0;
}