#include<bits/stdc++.h>

using namespace std;
// #define int long long int

signed main(){
    int t; cin >> t;
    for(;t--;){
        int n, k;
        cin >> n >> k;
        if (n == 1){
            printf("1\n1\n");
        }
        if (n >= 3){
            if (k == 1 || k == n){
                cout << -1 << endl; continue;
            }
            printf("3\n1 %d %d\n", k, k+1);
        }
    }
    return 0;
}
