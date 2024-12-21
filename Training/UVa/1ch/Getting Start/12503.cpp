#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<string> q(n);
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            if (s == "SAME") {
                int c;
                cin >> s >> c;
                q[i] = q[c-1];
            }else{
                q[i] = s;
            }
        }
        int ans = 0;
        for(auto s : q){
            if (s == "LEFT") ans--;
            if (s == "RIGHT") ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}