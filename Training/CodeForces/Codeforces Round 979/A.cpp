#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int m1 = 1e9, m2 = 0;
        for(int i = 0; i < n; i++) {
            int c;
            cin >> c;
            m2 = max(c, m2); m1 = min(c, m1);
        }
        cout << (n-1)*(m2-m1) << endl;
    }   
}