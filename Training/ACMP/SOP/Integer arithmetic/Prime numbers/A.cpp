#include<bits/stdc++.h>
  
using namespace std;

  
int main(){
    int n = 1000, number;
    cin >> number;
    vector<int> primes;
    vector<int> vis(n, 1);
    for(int i = 2; i <= n; i++){
        if (vis[i]){
            primes.push_back(i);
            for(int j = i * 2; j <= n; j += i){
                vis[j] = 0;
            }
        }
    }
    
    for(auto p1 : primes){
        for(auto p2 : primes){
            if (p1 + p2 == number){
                cout << p1 << " " << p2;
                return 0;
            }
        }
    }
}