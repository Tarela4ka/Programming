#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        char p, c;
        bool f = false;
        cin >> n;
        cin >> p;
        if (p == '1') f = true;
        for(int i = 0; i < n-1; i++){
            cin >> c;
            if (c == p && c == '1') f = true;
            p = c;
        }
        if (p == '1') f = true;
        if (f) cout << "YES";
        else cout << "NO";
        cout << endl;
    }    
}