#include<bits/stdc++.h>
  
using namespace std;
  
int main(){
    int n,m; cin >> n >> m;
    for(int i = 0; i < gcd(n,m); i++){
        cout << 1;
    }
    return 0;
}