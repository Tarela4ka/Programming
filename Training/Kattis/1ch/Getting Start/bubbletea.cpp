#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <set>
 
using namespace std;
 
int main(){
    int n, m;
    cin >> n;
    vector<int> p1(n);
    for(auto& c : p1) cin >> c;
    cin >> m;
    vector<int> p2(m);
    for(auto& c : p2) cin >> c;
    int minP = 1e9;
    for(int i = 0; i < n; i++){
        int o; cin >> o;
        for(int j = 0; j < o; j++){
            int c;
            cin >> c;
            // cout << p1[i]+p2[c-1] << endl;
            minP = min(minP, p1[i]+p2[c-1]);
        }
    }
    int money; cin >> money;
    cout << max((money/minP)-1, 0);
}