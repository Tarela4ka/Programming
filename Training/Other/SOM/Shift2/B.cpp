#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k, ans = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int c, p = 0;
        cin >> c;
        if (c%2 == 0) {
            p++;
            while(c%2 == 0) c/=2;
        }
        int s = sqrt(c)+1;
        for(int j = 3; j <= s && c != 1; j+=2){
            if (c%j == 0) {
                p++;
                while(c%j == 0) c/=j;
            }
        }
        if (c != 1) p++;
        // cout << p << " ";
        if (p == k){
            ans++;
        }
    }
    cout << ans;
    return 0;
}