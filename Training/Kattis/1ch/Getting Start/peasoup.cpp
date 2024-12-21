#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <stack>

using namespace std;

signed main(){
    int n; cin >> n;
    string ans = "Anywhere is fine I guess"; bool f = false;
    for(int i = 0; i < n; i++){
        int m; string name;
        cin >> m;
        getline(cin, name);
        getline(cin, name);
        string s; 
        bool pea = 0, pan = 0;
        for(int j = 0; j < m; j++){
            getline(cin, s);
            if (s == "pancakes") pan = 1;
            if (s == "pea soup") pea = 1;
        }
        if (pea && pan && !f) {
            ans = name;
            f = true;
        }
    }
    cout << ans;
}