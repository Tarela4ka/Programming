#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
using ll = long long;

int main(){
    int n, minI, minE = 1e9+10;
    cin >> n;
    for(int i = 0; i < n; i++){
        int c; cin >> c;
        if (minE > c){
            minI = i;
            minE = c;
        }
    }
    cout << minI;
    return 0;
}