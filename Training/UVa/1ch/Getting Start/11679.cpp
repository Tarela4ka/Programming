#include<bits/stdc++.h>

using namespace std;

int main(){
    while(true){
        int n,m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        vector<int> money(n);
        vector<pair<pair<int, int>, int>> debts(m);
        for(auto& c : money) cin >> c;
        for(auto& [e,p] : debts){ 
            auto& [a, b] = e;
            cin >> a >> b >> p;
            a--; b--;
        }
        while(true){
            bool f2 = false;
            for(auto& [e, p] : debts){
                auto [a,b] = e;
                if (money[a] != 0 && p != 0){
                    int need = min(money[a], p);
                    // cout << a << " " << b << ' ' << money[a] << " " << p << endl;
                    p -= need;
                    money[a] -= need;
                    money[b] += need;
                    f2 = true;
                }
            }
            if (!f2) break;
        }
        // for(auto c : money){
        //     cout << c << " ";
        // }
        // cout << endl;

        bool ans = true;
        for(auto& [e, p] : debts){
            if (p != 0) ans = false;
            // cout << p << " ";
        } 
        // cout << endl;
        if (ans) cout << "S\n";
        else cout << "N\n";
    }
    return 0;
}
