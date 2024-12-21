#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int cn = 1; cn <= t; cn++){
        int n;
        cin >> n;
        int maxE = -1e9;
        for(int i = 0; i < n; i++){
            int c;
            cin >> c;
            maxE = max(c, maxE);
        }
        printf("Case %d: %d\n", cn, maxE);
    }
    return 0;
}