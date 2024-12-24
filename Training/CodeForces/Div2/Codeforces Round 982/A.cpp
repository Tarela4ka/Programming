#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int max1 = 0,max2 = 0;
        for(int i = 0; i < n; i++){
            int c; 
            cin >> c;
            max1 = max(max1, c);
            cin >> c;
            max2 = max(max2, c);
        }
        cout << 2*(max2+max1) << endl; 
    }
}