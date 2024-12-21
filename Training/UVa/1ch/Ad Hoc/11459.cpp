#include<bits/stdc++.h>

using namespace std;
// #define int long long int
// #define all(a) a.begin(), a.end()

signed main(){
    int n; 
    cin >> n;
    while(n--){
        int p, l, r; cin >> p >> l >> r;
        vector<int> pos(p, 1);
        vector<pair<int, int>> laders(l);
        for(auto& [s,f] : laders){
            cin >> s >> f;
        }
        bool game = false;
        for(int i = 0; i < r; i++){
            int c; cin >> c;
            if (game) continue;
            int ind = i % p;
            pos[ind] = min(c+pos[ind], 100);
            for(auto [s, f] : laders){
                if (pos[ind] == s) {
                    pos[ind] = f;
                    break;
                }
            }
            if (pos[ind] == 100) 
                game = true;
        }
        for(int i = 0; i < p; i++){
            printf("Position of player %d is %d.\n", i+1, pos[i]);
        }
    }
    return 0;
}