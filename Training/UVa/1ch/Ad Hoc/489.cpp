#include<bits/stdc++.h>

using namespace std;
// #define int long long int
// #define all(a) a.begin(), a.end()

signed main(){
    int t = 1;
    while(true){
        int n; cin >> n;
        if (n == -1) break;
        string s1, s2;
        cin >> s1 >> s2;
        map<char, int> r, r2;
        int guessed = 0;
        for(auto c : s1) {
            if (r[c] == 0){
                guessed++;
            }
            r[c]++;
        }
        int a = 0; bool win = false;
        for(auto c : s2){
            if (r[c] == 0){
                if (r2[c] == 0){
                    a++;
                    r2[c]=1;
                }
            }else{
                guessed--; 
                r[c] = 0; 
                r2[c]=1;
                if (guessed == 0 && a < 7) win = true;
            }
        }
        // cout << a << endl;
        cout << "Round " << n << endl; 
        if (win){
            cout << "You win.\n";
        }else if (a < 7){
            cout << "You chickened out.\n";
        }else{
            cout << "You lose.\n";
        }
    }
    return 0;
}
