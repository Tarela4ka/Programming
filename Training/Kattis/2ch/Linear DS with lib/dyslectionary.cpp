#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
// #define int long long int
#define all(a) a.begin(), a.end()
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;

string s;
vs a;

void getAns(){
    int maxL = 0;
    for(auto c : a) if (c.length() > maxL) maxL = c.length();
    for(auto& c : a){
        reverse(all(c));
        while(c.length() < maxL) c += " ";
    } 
    sort(all(a));
    for(auto& c : a) reverse(all(c));
    for(auto c : a) cout << c << '\n';
    a.clear();
}

signed main(){
    while(getline(cin, s)){
        if (s != "") {
            a.push_back(s);
            continue;
        }
        getAns();
        cout << '\n';
    }
    getAns();
}