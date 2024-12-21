#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    for(int i = 1; i < s.length()-1; i++){
        if (s[i] != s[i-1] && s[i] != s[i+1] && s[i-1] != s[i+1]){
            s.replace(i-1, 3, "C");
        }
    }   
    for(int i = 0; i < s.length(); i++){
        if (s[i] == 'R') s[i] = 'S';
        else if (s[i] == 'B') s[i] = 'K';
        else if (s[i] == 'L') s[i] = 'H';
    }
    cout << s << '\n';
    return 0;
}