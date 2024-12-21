#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<unordered_map>

using namespace std;

int main(){
    int n;
    char dom;
    unordered_map<char, int> d, nd;
    d['A'] = 11; nd['A'] = 11;
    d['K'] = 4;  nd['K'] = 4;
    d['Q'] = 3;  nd['Q'] = 3;
    d['J'] = 20; nd['J'] = 2;
    d['T'] = 10; nd['T'] = 10;
    d['9'] = 14; nd['9'] = 0;
    d['8'] = 0;  nd['8'] = 0;
    d['7'] = 0;  nd['7'] = 0;
    cin >> n >> dom;
    int ans = 0;
    for(int i = 0; i < 4*n; i++){
        string s;
        cin >> s;
        if (s[1] == dom) ans += d[s[0]];
        else ans += nd[s[0]];
    }
    cout << ans;
}