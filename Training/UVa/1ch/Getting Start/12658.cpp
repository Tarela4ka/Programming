#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> q(5);
    getline(cin, q[0]);

    for(int i = 0; i < 5; i++)
        getline(cin, q[i]);

    // for(auto c : q) cout << c << endl;
    string ans = "";
    for(int i = 0; i < 4*n; i += 4){
        // cout << i << endl;
        if (q[0][i] == '.') ans += "1";
        else 
            if (q[3][i] == '.') ans += "3";
            else ans += "2";
    }
    cout << stoi(ans) << '\n';
    return 0;
}