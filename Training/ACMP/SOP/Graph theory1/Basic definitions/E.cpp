#include <bits/stdc++.h>

using namespace std;

int main(){
    long long t, n1, n2;
    cin >> t >> n1 >> n2;
    int l = t, r = t;
    for (; !(pow(2, l - 1) <= n1 && pow(2, l) >= n1);){
        l--;
    }
    for (; !(pow(2, r - 1) <= n2 && pow(2, r) >= n2);){
        r--;
    }

    for (; n1 != n2; ){
        if (l == r){
            n1 /= 2; n2 /= 2;
            l--; r--;    
        }
        if (l > r){
            n1 /= 2; 
            l--;
        }
        if (r > l){
            n2 /= 2;
            r--;
        }
        
    }
    cout << n1;
}