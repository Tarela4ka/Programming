#include<bits/stdc++.h>

using namespace std;
#define int long long int
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for(int caseN = 0; caseN < t; caseN++){
        map<int, set<int>> p;
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            int c; cin >> c;
            p[c].insert(i);
        } 
        
    }
    return 0;
}