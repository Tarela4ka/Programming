#include<bits/stdc++.h>

using namespace std;
// #define int long long int
// #define all(a) a.begin(), a.end()

signed main(){
    int n;
    while(true){
        cin >> n;
        if (n == 0) break;
        vector<int> p(n, 0);
        bool f = true;
        for(int i = 0; i < n; i++){
            int a,b; cin >> a >> b;
            if (i+b >= 0 && i+b < n && p[i+b] == 0){
                p[i+b] = a;
            }else{
                f = false;
            }
        }
        if(!f) {
            cout << -1 << '\n';
            continue;
        }
        cout << p[0];
        for(int i = 1; i < n; i++)
            cout << " " << p[i];
        cout << '\n';
    }
    return 0;
}