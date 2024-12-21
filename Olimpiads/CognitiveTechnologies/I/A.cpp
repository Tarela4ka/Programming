#include<bits/stdc++.h>

using namespace std;
#define int long long int
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()

signed main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for(int caseN = 0; caseN < t; caseN++){
        int n, m;
        cin >> n >> m;
        if (n > m){
            cout << -1 << endl;
            continue;
        }
        for(int i = 0; i < n-1; i++)
            cout << 1 << ' ';
        cout << m-n+1 << endl;
    }
    return 0;
}