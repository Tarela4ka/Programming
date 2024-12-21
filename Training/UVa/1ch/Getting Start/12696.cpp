#include<bits/stdc++.h>

using namespace std;

int main(){
    int t, ans = 0;
    cin >> t;
    while(t--){
        double len, wid, dep, weight;
        cin >> len >> wid >> dep >> weight;
        if ((len+wid+dep <= 125 || (len <= 56 && wid <= 45 && dep <= 25)) && weight <= 7){
            cout << 1; ans++;
        } else cout << 0;
        cout << '\n';
    }
    cout << ans << '\n';
    return 0;
}