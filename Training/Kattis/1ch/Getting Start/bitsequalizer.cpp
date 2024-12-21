#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(){
    int t; cin >> t;
    string s1,s2;
    getline(cin, s1);
    for(int i = 0; i < t; i++){
        getline(cin, s1); getline(cin, s2);
        printf("Case %d: ", i+1);
        map<char, int> w1, w2;
        for(auto c : s1) w1[c]++;
        for(auto c : s2) w2[c]++;
        int no = w2['1']-w1['1'], nz = w2['0'] - w1['0'];
        // cout << no << " " << nz << endl;
        if (no < 0) {
            cout << "-1\n"; 
            continue;
        }
        int ans = 0;
        for(int i = 0; i < s1.length(); i++){
            if (s1[i] == '?'){
                if (no > 0 && s2[i] == '1'){
                    no--; s1[i] = '1'; ans++;
                } else {
                    s1[i] = '0'; ans++; nz--;
                }
            }
        }
        // cout << no << " " << nz << endl;
        for(int i = 0; i < s1.length() && no > 0; i++){
            if (s1[i] == '0' && s2[i] == '1'){
                s1[i] = '1'; ans++; nz++; no--;
            }
        } 
        // cout << s1 << endl;
        int dif = 0;
        for(int i = 0; i < s1.length(); i++) if (s1[i] != s2[i]) dif++;
        ans += dif/2;
        cout << ans << "\n";
    }
    return 0;
}