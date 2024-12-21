#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
using ll = long long;

ll len(ll n){
    ll res;
    for(res = 0;n != 0; n/=10, res++);
    return res;
}

int main(){
    while(true){
        string s;
        getline(cin, s);
        if (s == "END") return 0;
        string sp = s; int ans = 1;
        for(; true;ans++){
            s = to_string(s.length());
            if (sp == s) break;
            sp = s;
        }
        cout << ans << endl;
    }
    return 0;
}             
