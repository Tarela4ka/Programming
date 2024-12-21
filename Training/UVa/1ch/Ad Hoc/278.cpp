#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n,m;
        char c;
        cin >> c >> n >> m;
        if (c == 'r' || c == 'Q'){
            cout << min(n,m);
        }else if (c == 'K'){
            cout << (m+m%2)/2*(n+n%2)/2;
        }else if (c == 'k'){
            cout << ceil((double)n*m/2);
        }
        cout << '\n';
    }
    return 0;
}